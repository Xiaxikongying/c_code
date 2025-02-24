#include <iostream>
#include <atomic>
using namespace std;

template <typename T>
class SharedPtr
{
private:
    T *ptr;
    atomic<int> *count; 

public:
    void cleanup()
    {
        if (count && count->fetch_sub(1) == 0)
        {
            delete ptr;
            delete count;
        }
        cout << " clean" << endl;
    }

    // 无参  裸指针  拷贝构造函数
    SharedPtr() : ptr(nullptr), count(nullptr) {}
    explicit SharedPtr(T *p) : ptr(p), count(new atomic<int>(1)) {} // 防止隐式构造{}
    SharedPtr(const SharedPtr &other) : ptr(other.ptr), count(other.count)
    {
        if (other.count)
            count->fetch_add(1); //----> (*count)++
    }
    // 移动拷贝构造函数
    SharedPtr(const SharedPtr &&other)
    {
        if (this != &other)
        {
            cleanup();
            ptr = other.ptr;
            ptr.count = other.count;
            other.count = nullptr;
            other.ptr = nullptr;
        }
    }
    ~SharedPtr() // 析构函数
    {
        cleanup();
    }
    // 赋值函数
    SharedPtr &operator=(const SharedPtr &other)
    {
        if (this != &other)
        {
            cleanup();
            ptr = other.ptr;
            count = other.count;
            count->fetch_add(1);
        }
        return *this;
    }
    // 移动赋值函数
    SharedPtr &operator=(const SharedPtr &&other)
    {
        if (this != &other)
        {
            cleanup();
            ptr = other.ptr;
            count = other.count;
            other.count = nullptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T &operator*() // 取值
    {
        return *ptr;
    }

    T *get()
    {
        return ptr;
    }

    int getcount() // 获取引用计数
    {
        return count ? count->load() : 0;
    }

    T *operator->()
    {
        return ptr;
    }
};

class B;
class A
{
public:
    SharedPtr<B> pb;
    ~A()
    {
        pb.cleanup();
    }
};

class B
{
public:
    SharedPtr<A> pa;
    ~B()
    {
        pa.cleanup();
    }
};

int main()
{
    int *ca, *cb;
    {

        SharedPtr<A> PA(new A);
        SharedPtr<B> PB(new B);
        PA->pb = PB;
        PB->pa = PA;
        cout << PA.getcount() << endl;
        cout << PB.getcount() << endl;
    }
    system("pause");
    return 0;
}
