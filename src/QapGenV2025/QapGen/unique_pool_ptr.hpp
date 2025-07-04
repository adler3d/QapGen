#include <vector>
#include <memory>
#include <cstddef>
#include <cassert>
#include <new>
#include <mutex>
#include <type_traits>

//static size_t g_unique_pool_ptr_counter = 0;
//unordered_map<size_t,size_t> t2n,t2c;
//t_meta_lexer::t_attr::ProxySys$$::GetFullName();
unordered_map<string,size_t> t2maxn,t2c;
#define QAP_UPP_FREE_LSIT
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

    // Конструктор перемещения
    Chunk(Chunk&& other) noexcept
      : data(other.data), capacity(other.capacity), used(other.used) {
      other.data = nullptr;
      other.capacity = 0;
      other.used = 0;
    }

    Chunk& operator=(Chunk&& other) noexcept {
      if (this != &other) {
        ::operator delete(data);
        data = other.data;
        capacity = other.capacity;
        used = other.used;
        other.data = nullptr;
        other.capacity = 0;
        other.used = 0;
      }
      return *this;
    }

    // Запретить копирование
    Chunk(const Chunk&) = delete;
    Chunk& operator=(const Chunk&) = delete;
  };

  std::vector<Chunk> chunks;
  #ifdef QAP_UPP_FREE_LSIT
  std::vector<T*> free_list; // Список освобождённых объектов для повторного использования
  #endif
  size_t chunk_size;
  size_t curn=0;
  //std::mutex mtx;

//template<typename T>
  Pool(size_t chunk_sz = 8+0*192*8/sizeof(T)) : chunk_size(chunk_sz) {chunks.reserve(64);/*free_list.reserve(chunk_sz/2);*/}

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
    //std::lock_guard<std::mutex> lock(mtx);
    t2c[T::ProxySys$$::GetFullName()]++;
    curn++;
    t2maxn[T::ProxySys$$::GetFullName()]=max(t2maxn[T::ProxySys$$::GetFullName()],curn);
    T* ptr = nullptr;
    #ifdef QAP_UPP_FREE_LSIT
    if (!free_list.empty()) {
      ptr = free_list.back();
      free_list.pop_back();
      // Конструируем объект заново на месте
      new(ptr) T(std::forward<Args>(args)...);
      return ptr;
    }
    #endif
    if (chunks.empty() || chunks.back().used == chunks.back().capacity) {
      chunks.emplace_back(Chunk{chunk_size});
    }
    Chunk&chunk=chunks.back();
    ptr = &chunk.data[chunk.used++];
    new(ptr) T(std::forward<Args>(args)...);
    return ptr;
  }

  void deallocate(T* ptr) {
    if (!ptr) return;
    curn--;
    // Вызываем деструктор объекта
    ptr->~T();
    #ifdef QAP_UPP_FREE_LSIT
    // Добавляем объект в free_list для повторного использования
    free_list.push_back(ptr);
    #endif
  }

  void clear() {
    //std::lock_guard<std::mutex> lock(mtx);
    // Вызываем деструкторы для всех занятых объектов в чанках
    for (auto& chunk : chunks) {
      for (size_t i = 0; i < chunk.used; ++i) {
        chunk.data[i].~T();
      }
      chunk.used = 0;
    }
    #ifdef QAP_UPP_FREE_LSIT
    free_list.clear();
    #endif
  }

  ~Pool() {
    clear();
  }
};

template<typename T>
struct PoolDeleter {
  void operator()(T* ptr) const noexcept {
    if (ptr) {
      Pool<T>::instance().deallocate(ptr);
    }
  }
};

template<typename T>
class UniquePoolPtr {
  T* ptr = nullptr;
  PoolDeleter<T> deleter;

public:
  UniquePoolPtr() = default;

  explicit UniquePoolPtr(T* p) : ptr(p) {}

  UniquePoolPtr(const UniquePoolPtr&) = delete;
  UniquePoolPtr& operator=(const UniquePoolPtr&) = delete;

  UniquePoolPtr(UniquePoolPtr&& other) noexcept
    : ptr(other.ptr), deleter(std::move(other.deleter)) {
      other.ptr = nullptr;
  }

  UniquePoolPtr& operator=(UniquePoolPtr&& other) noexcept {
    if (this != &other) {
      reset();
      ptr = other.ptr;
      deleter = std::move(other.deleter);
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
      deleter(ptr);
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
