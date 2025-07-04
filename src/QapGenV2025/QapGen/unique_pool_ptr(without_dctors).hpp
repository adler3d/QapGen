#include <vector>
#include <memory>
#include <cstddef>
#include <cassert>
#include <new>
#include <mutex>
#include <type_traits>

static size_t g_unique_pool_ptr_counter = 0;

template<typename T>
class Pool {
  struct Chunk {
    T* data;
    size_t capacity;
    size_t used;

    Chunk(size_t cap) : capacity(cap), used(0) {
      data = static_cast<T*>(::operator new(sizeof(T) * capacity));
    }
    ~Chunk() {
      ::operator delete(data);
    }
  };

  std::vector<std::unique_ptr<Chunk>> chunks;
  std::vector<T*> free_list; // Список освобождённых объектов для повторного использования
  size_t chunk_size;
  //std::mutex mtx;

  Pool(size_t chunk_sz = 8) : chunk_size(chunk_sz) {}

public:
  Pool(const Pool&) = delete;
  Pool& operator=(const Pool&) = delete;

  static Pool& instance() {
    static Pool pool;
    return pool;
  }

  template<typename... Args>
  T* allocate(Args&&... args) {
    g_unique_pool_ptr_counter++;
    //return new T(std::forward<Args>(args)...);
    //std::lock_guard<std::mutex> lock(mtx);

    T* ptr = nullptr;
    /*if (!free_list.empty()) {
      ptr = free_list.back();
      free_list.pop_back();
      // Конструируем объект заново на месте
      new(ptr) T(std::forward<Args>(args)...);
      return ptr;
    }*/

    if (chunks.empty() || chunks.back()->used == chunks.back()->capacity) {
      chunks.emplace_back(std::make_unique<Chunk>(chunk_size));
    }
    Chunk* chunk = chunks.back().get();
    ptr = &chunk->data[chunk->used++];
    new(ptr) T(std::forward<Args>(args)...);
    return ptr;
  }

  void deallocate(T* ptr) {
    return;
    if (!ptr) return;
    // Вызываем деструктор объекта
    ptr->~T();
    // Добавляем объект в free_list для повторного использования
    free_list.push_back(ptr);
  }

  void clear() {
    //std::lock_guard<std::mutex> lock(mtx);
    // Вызываем деструкторы для всех занятых объектов в чанках
    for (auto& chunk : chunks) {
      for (size_t i = 0; i < chunk->used; ++i) {
        chunk->data[i].~T();
      }
      chunk->used = 0;
    }
    free_list.clear();
  }

  ~Pool() {
    clear();
  }
};

// Умный указатель с поддержкой пула
template<typename T>
class UniquePoolPtr {
  T* ptr = nullptr;

public:
  UniquePoolPtr() = default;

  explicit UniquePoolPtr(T* p) : ptr(p) {}

  UniquePoolPtr(const UniquePoolPtr&) = delete;
  UniquePoolPtr& operator=(const UniquePoolPtr&) = delete;

  UniquePoolPtr(UniquePoolPtr&& other) noexcept : ptr(other.ptr) {
    other.ptr = nullptr;
  }

  UniquePoolPtr& operator=(UniquePoolPtr&& other) noexcept {
    if (this != &other) {
      reset();
      ptr = other.ptr;
      other.ptr = nullptr;
    }
    return *this;
  }

  ~UniquePoolPtr() {
    reset();
  }

  T* get() const { return ptr; }
  T* operator->() const { return ptr; }
  T& operator*() const { return *ptr; }

  void reset(T* p = nullptr) {
    if (ptr) {
      Pool<T>::instance().deallocate(ptr);
    }
    ptr = p;
  }

  T* release() {
    T* temp = ptr;
    ptr = nullptr;
    return temp;
  }

  explicit operator bool() const {
    return ptr != nullptr;
  }
  
  template<typename U>
  UniquePoolPtr& operator=(UniquePoolPtr<U>&& other) noexcept {
    static_assert(std::is_convertible<U*, T*>::value, "Incompatible pointer types");
    reset(other.release());
    return *this;
  }
  
  template<typename U>
  UniquePoolPtr(UniquePoolPtr<U>&& other) noexcept {
    static_assert(std::is_convertible<U*, T*>::value, "Incompatible pointer types");
    ptr = other.release();
  }

  UniquePoolPtr& operator=(std::nullptr_t) noexcept {
    reset();
    return *this;
  }
};

// Функция создания объекта с выделением из пула
template<typename T, typename... Args>
UniquePoolPtr<T> make_unique_pool(Args&&... args) {
  T* p = Pool<T>::instance().allocate(std::forward<Args>(args)...);
  return UniquePoolPtr<T>(p);
}
