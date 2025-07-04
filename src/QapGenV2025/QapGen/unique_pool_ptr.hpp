#include <vector>
#include <memory>
#include <cstddef>
#include <cassert>
#include <new>
#include <mutex>
#include <type_traits>
#include <unordered_set>

#define QAP_UPP_FREE_LIST
#define QAP_UPP_COUNTERS
#ifdef QAP_UPP_COUNTERS
unordered_map<string,size_t> t2maxn,t2c;
#endif
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
  #ifdef QAP_UPP_FREE_LIST
  std::vector<T*> free_list; // Список освобождённых объектов для повторного использования
  #endif
  size_t chunk_size;
  #ifdef QAP_UPP_COUNTERS
  size_t curn=0;
  #endif
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
    #ifdef QAP_UPP_COUNTERS
    curn++;
    t2maxn[T::ProxySys$$::GetFullName()]=max(t2maxn[T::ProxySys$$::GetFullName()],curn);
    #endif
    T* ptr = nullptr;
    #ifdef QAP_UPP_FREE_LIST
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
    #ifdef QAP_UPP_COUNTERS
    curn--;
    #endif
    // Вызываем деструктор объекта
    ptr->~T();
    #ifdef QAP_UPP_FREE_LIST
    // Добавляем объект в free_list для повторного использования
    free_list.push_back(ptr);
    #endif
  }


  void clear(bool keep_chunks = true) {
    #ifdef QAP_UPP_FREE_LIST
    std::unordered_set<T*> free_set(free_list.begin(), free_list.end());
    #else
    std::unordered_set<T*> free_set;
    #endif
    //size_t destroyed=0;size_t free=0;size_t cap=chunk_size*chunks.size();
    for (auto& chunk : chunks) {
      //size_t d=0;
      for (size_t i = 0; i < chunk.used; ++i) {
        #ifdef QAP_UPP_FREE_LIST
        T* obj = &chunk.data[i];
        if (free_set.find(obj) == free_set.end()) {
          QapNoWay();
          obj->~T();//d++;destroyed++;
        }
        #else
        obj->~T();
        #endif
      }
      //free+=chunk_size-chunk.used;
      chunk.used = 0;
    }
    //QapAssert(destroyed+free_list.size()==cap-free);
    if (!keep_chunks) {
      chunks.clear();
    }
    #ifdef QAP_UPP_FREE_LIST
    free_list.clear();
    #endif
  }
  ~Pool() {
    clear();
  }
};

struct IPoolDeleterBase {
  virtual ~IPoolDeleterBase() = default;
  virtual void deleteObject(void* ptr) const noexcept = 0;
};

template<typename T>
struct PoolDeleter : IPoolDeleterBase {
  void deleteObject(void* ptr) const noexcept override {
    if (ptr) {
      Pool<T>::instance().deallocate(static_cast<T*>(ptr));
    }
  }
};
#ifdef QAP_UPP_DEBUG
static int g_id=0;
#endif
template<typename T>
struct UniquePoolPtr {
  T* ptr = nullptr;
  const IPoolDeleterBase* deleter = nullptr;
  #ifdef QAP_UPP_DEBUG
  size_t id=0;
  #endif
public:
  UniquePoolPtr() = default;

  UniquePoolPtr(T* p, const IPoolDeleterBase* d): ptr(p), deleter(d){
    #ifdef QAP_UPP_DEBUG
    if(g_id==9719){
      int gg=1;
    }
    id=g_id++;
    #endif
  }

  ~UniquePoolPtr() {
    reset();
  }

  void reset(T* p = nullptr) {
    if (ptr && deleter) {
      deleter->deleteObject(ptr);
    }
    ptr = p;
  }
public:
  UniquePoolPtr(const UniquePoolPtr&) = delete;
  UniquePoolPtr& operator=(const UniquePoolPtr&) = delete;

  UniquePoolPtr(UniquePoolPtr&& other)noexcept:ptr(other.ptr),deleter(std::move(other.deleter)){
    other.ptr = nullptr;
    #ifdef QAP_UPP_DEBUG
    id=other.id;
    #endif
  }

  UniquePoolPtr& operator=(UniquePoolPtr&& other) noexcept {
    if (this != &other) {
      reset();
      ptr = other.ptr;
      deleter = std::move(other.deleter);
      other.ptr = nullptr;
      #ifdef QAP_UPP_DEBUG
      id=other.id;
      #endif
    }
    return *this;
  }
  
  T* get() const { return ptr; }
  T* operator->() const { return ptr; }
  T& operator*() const { return *ptr; }

  T* release() {
    T* temp = ptr;
    ptr = nullptr;
    deleter = nullptr; 
    return temp;
  }

  explicit operator bool() const {
    return ptr != nullptr;
  }

  template<typename U>
  UniquePoolPtr& operator=(UniquePoolPtr<U>&& other) noexcept {
    static_assert(std::is_convertible<U*, T*>::value, "Incompatible pointer types");
    const IPoolDeleterBase* new_deleter = other.deleter;
    T* new_ptr = other.release();
    reset();
    ptr = new_ptr;
    deleter = new_deleter;
    #ifdef QAP_UPP_DEBUG
    id = other.id;
    other.id = -1;
    #endif
    return *this;
  }
  template<typename U>
  UniquePoolPtr(UniquePoolPtr<U>&& other) noexcept
    : ptr(nullptr), deleter(nullptr), id(0) {
    static_assert(std::is_convertible<U*, T*>::value, "Incompatible pointer types");
    deleter = other.deleter;
    #ifdef QAP_UPP_DEBUG
    id = other.id;
    other.id = -1;
    #endif
    ptr = other.release();
  }
  UniquePoolPtr& operator=(std::nullptr_t) noexcept {
    reset();
    return *this;
  }
};

template<typename T, typename... Args>
UniquePoolPtr<T> make_unique_pool(Args&&... args) {
  static const PoolDeleter<T> static_deleter_instance;
  T* raw_ptr = Pool<T>::instance().allocate(std::forward<Args>(args)...);
  return UniquePoolPtr(raw_ptr, &static_deleter_instance);
}