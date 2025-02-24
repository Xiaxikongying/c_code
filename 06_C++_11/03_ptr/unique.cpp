template <typename T>
class UniquePtr
{
private:
    T *ptr;

public:
    // 构造函数
    explicit UniquePtr(T *p = nullptr) : ptr(p) {}
    // 禁用拷贝构造和拷贝赋值
    UniquePtr(const UniquePtr &) = delete;
    UniquePtr &operator=(const UniquePtr &) = delete;

    // 实现移动构造和移动赋值
    UniquePtr(UniquePtr &&other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    UniquePtr &operator=(UniquePtr &&other) noexcept
    {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // 析构函数
    ~UniquePtr()
    {
        delete ptr;
    }

    // 重载*和->操作符
    T &operator*() const
    {
        return *ptr;
    }

    T *operator->() const
    {
        return ptr;
    }

    // 获取原始指针
    T *get() const
    {
        return ptr;
    }

    // 释放管理的指针，并返回它
    T *release()
    {
        T *temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // 重置指针
    void reset(T *p = nullptr)
    {
        delete ptr;
        ptr = p;
    }
};
