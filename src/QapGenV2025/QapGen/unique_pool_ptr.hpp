#include <vector>
#include <memory>
#include <cstddef>
#include <cassert>
#include <new>
#include <mutex>

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
  size_t chunk_size;
  std::mutex mtx;

  Pool(size_t chunk_sz = 300) : chunk_size(chunk_sz) {}

public:
  Pool(const Pool&) = delete;
  Pool& operator=(const Pool&) = delete;

  static Pool& instance() {
    static Pool pool;
    return pool;
  }

  template<typename... Args>
  T* allocate(Args&&... args) {
    std::lock_guard<std::mutex> lock(mtx);
    if (chunks.empty() || chunks.back()->used == chunks.back()->capacity) {
      chunks.emplace_back(std::make_unique<Chunk>(chunk_size));
    }
    Chunk* chunk = chunks.back().get();
    T* ptr = &chunk->data[chunk->used++];
    // Конструируем объект в выделенной памяти
    new(ptr) T(std::forward<Args>(args)...);
    return ptr;
  }

  void deallocate(T* ptr) {
    if (!ptr) return;
    // Вызываем деструктор объекта, но память не освобождаем (пул освобождается целиком)
    ptr->~T();
    // Можно добавить логику повторного использования памяти, но это усложняет реализацию
  }

  void clear() {
    std::lock_guard<std::mutex> lock(mtx);
    for (auto& chunk : chunks) {
      // Вызываем деструкторы для всех объектов в чанках
      for (size_t i = 0; i < chunk->used; ++i) {
        chunk->data[i].~T();
      }
      chunk->used = 0;
    }
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
