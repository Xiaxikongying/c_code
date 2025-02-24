#include <iostream>

template <typename T>
class MySharedPtr
{
private:
    T *ptr;     // 指向管理的对象
    int *count; // 引用计数器

public:
    // 构造函数
    explicit MySharedPtr(T *p = nullptr) : ptr(p)
    {
        // 如果传入的指针为空，初始化引用计数为 0
        if (!ptr)
            *count = 0;
        else
            count = new int(1);
    }

    // 拷贝构造函数
    MySharedPtr(const MySharedPtr &other)
    {
        ptr = other.ptr;     // 复制其他对象的指针
        count = other.count; // 复制其他对象的引用计数器
        if (ptr)
            (*count)++; // 增加引用计数
    }

    // 移动构造函数
    MySharedPtr(MySharedPtr &&other)
    {
        ptr = other.ptr;     // 复制其他对象的指针
        count = other.count; // 复制其他对象的引用计数器

        // 让其他对象失效
        other.ptr = nullptr;
        other.count = nullptr;
    }

    // 拷贝赋值运算符
    MySharedPtr &operator=(const MySharedPtr &other)
    {
        if (this != &other)
        {              // 防止自赋值
            release(); // 先释放当前对象管理的资源

            // 复制其他对象的指针和引用计数器
            ptr = other.ptr;
            count = other.count;
            if (ptr)
                (*count)++; // 增加引用计数
        }
        return *this;
    }

    // 移动赋值运算符
    MySharedPtr &operator=(MySharedPtr &&other)
    {
        if (this != &other)
        {              // 防止自赋值
            release(); // 先释放当前对象管理的资源

            // 转移其他对象的资源到当前对象
            ptr = other.ptr;
            count = other.count;

            // 让其他对象失效
            other.ptr = nullptr;
            other.count = nullptr;
        }
        return *this;
    }

    // 析构函数
    ~MySharedPtr()
    {
        release(); // 释放资源
    }

private:
    // 释放资源的私有函数
    void release()
    {
        if (ptr)
        {
            (*count)--; // 减少引用计数
            if (*count == 0)
            { // 如果没有引用，删除对象和计数器
                delete ptr;
                delete count;
            }
        }
    }
};
