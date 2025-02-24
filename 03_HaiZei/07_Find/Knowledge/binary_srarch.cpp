#include <iostream>
#include <time.h>
using namespace std;

void output(int *arr, int n, int ind = -1)
{
    int len = 0;
    for (int i = 0; i < n; i++)
        len += printf("%4d", i);
    printf("\n");
    for (int i = 0; i < len; i++)
        printf("-");
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (i == ind)
            printf(" |%d|", arr[i]);
        else
            printf("%4d", arr[i]);
    }

    printf("\n");
}

int binary_search(int *arr, int n, int x)
{
    int head = 0, tail = n - 1;
    int mid;
    while (head <= tail)
    {
        mid = (head + tail) / 2;
        //printf("[%d,%d], mid = %d , arr[%d]= %d\n", head, tail, mid, mid, arr[mid]);
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            head = mid + 1;
        else
            tail = mid - 1;
    }
    return -1;
}

void test_binary_search(int n)
{
    int *arr = (int *)malloc(sizeof(int) * n);
    arr[0] = rand() % 10;
    for (int i = 1; i < n; i++)
        arr[i] = arr[i - 1] + rand() % 10 + 1;
    output(arr, n);
    int x;
    while (~scanf("%d", &x))
    {
        if (x == -1)
            break;
        int ind = -1;
        ind = binary_search(arr, n, x);
        if (ind == -1)
            printf("没有找到该值\n");
        else
            output(arr, n, ind);
    }
    free(arr);
    return;
}



#define EXP 1e-2 // 10^(-2)

double binary_algorithm(double y)
{
    double head = 0, tail = 1000000;
    double mid;
    while (tail - head >= EXP)
    {
        mid = (head + tail) / 2.0;
        printf("[%lf,%lf], mid = %lf , shuishou[%lf]= %lf\n", head, tail, mid, mid, shuishou(mid));
        if (shuishou(mid) == y)
            return mid;
        if (shuishou(mid) < y)
            head = mid;
        else
            tail = mid;
    }
    return head; //两指针重合
}



#define MAX_N 10
int main()
{
    srand(time(0));
    test_binary_search(MAX_N);
    system("pause");
    return 0;
}
