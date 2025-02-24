#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define father(i) ((i) / 2)
#define left(i) ((i)*2)
#define right(i) ((i)*2 + 1)
#define swap(a, b)             \
    {                          \
        __typeof(a) __c = (a); \
        (a) = (b);             \
        (b) = __c;             \
    }
#define TEST(func, arr, n)                                    \
    {                                                         \
        printf("TEST: %s\n", #func);                          \
        int *temp = (int *)malloc(sizeof(int) * n);           \
        memcpy(temp, arr, sizeof(int) * n);                   \
        long long b = clock();                                \
        func(temp, n);                                        \
        long long e = clock();                                \
        if (check(temp, n))                                   \
        {                                                     \
            printf("OK\t");                                   \
        }                                                     \
        else                                                  \
        {                                                     \
            printf("FAIL\t");                                 \
        }                                                     \
        printf("%lld ms\n", 1000 * (e - b) / CLOCKS_PER_SEC); \
        free(temp);                                           \
    }

bool check(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

inline void up_updata(int *data, int i)
{
    while (i > 1 && data[i] > data[father(i)])
    {
        swap(data[i], data[father(i)]);
        i = father(i);
    }
    return;
}
inline void down_updata(int *data, int i, int n)
{
    while (left(i) <= n)
    {
        int ind = i, l = left(i), r = right(i);
        if (data[l] > data[i])
            ind = l;
        if (r <= n && data[r] > data[ind])
            ind = r;
        if (ind == i)
            break;
        swap(data[ind], data[i]);
        i = ind;
    }
    return;
}

inline void normal_heap_build(int *data, int n)
{
    for (int i = 2; i <= n; i++)
    {
        up_updata(data, i);
    }
    return;
}
inline void linear_heap_build(int *data, int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        down_updata(data, i, n);
    }
    return;
}

void heap_sort_final(int *data, int n)
{
    for (int i = n; i >= 2; i--)
    {
        swap(data[1], data[i]);
        down_updata(data, 1, i - 1);
    }
    return;
}

void normal_heap(int *arr, int n)
{
    int *data = arr - 1;
    normal_heap_build(data, n);
    heap_sort_final(data, n);
    return;
}
void linear_heap(int *arr, int n)
{
    int *data = arr - 1;
    linear_heap_build(data, n);
    heap_sort_final(data, n);
    return;
}

int *getRandData(int n)
{
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
    return arr;
}

int main()
{
    srand(time(0));
    int *arr = getRandData(1000000);
    TEST(normal_heap, arr, 1000000);
    TEST(linear_heap, arr, 1000000);

    system("pause");
    return 0;
}