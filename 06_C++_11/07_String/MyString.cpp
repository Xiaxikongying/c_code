#include <iostream>
#include <cstring>
using namespace std;
class MyString
{
private:
    char *data;
    int len;

public:
    MyString() : data(nullptr), len(0) {}

    MyString(const char *str)
    {
        len = strlen(str);
        data = new char[len + 1];
        strcpy(data, str);
    }
    MyString(const MyString &other)
    {
        len = other.len;
        data = new char[len + 1];
        strcpy(data, other.data);
    }
    MyString(MyString &&other) : data(other.data), len(other.len)
    {
        other.data = nullptr;
        other.len = 0;
    }
    ~MyString()
    {
        delete[] data;
    }

    MyString &operator=(const MyString &other)
    {
        if (this != &other)
        {
            delete[] data;
            len = other.len;
            data = new char[len + 1];
            strcpy(data, other.data);
        }
        return *this;
    }
    MyString &operator=(MyString &&other)
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            len = other.len;
            other.data = nullptr;
            other.len = 0;
        }
        return *this;
    }

    MyString &operator+=(const MyString &other)
    {
        len += other.len;
        char *NewData = new char[len + 1];
        strcpy(NewData, data);
        strcat(NewData, other.data);
        delete[] data;
        data = NewData;
        return *this;
    }

    MyString operator+(const MyString &other)
    {
        MyString res(*this);
        res += other;
        return res;
    }

    char &operator[](size_t index)
    {
        if (index >= len)
        {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    int length()
    {
        return len;
    }
    int size()
    {
        return len;
    }

    friend ostream &operator<<(ostream &os, MyString &str);
};
ostream &operator<<(ostream &os, MyString &str)
{
    os << str.data;
    return os;
}

int main()
{
    MyString str1("Hello");
    MyString str2(" World");
    MyString str3 = "hello";
    str3[2] = 'a';
    str1 += str2;
    cout << str1 << endl; // Outputs "Hello World"
    cout << str3 << endl;
    str3 = str1 + str2 + " " + str3;
    cout << str3 << endl;
    system("pause");
    return 0;
}
