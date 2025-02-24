#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

//顺序表

typedef struct vector
{
    int size, count;
    int *data;
    // data 是一段连续的存储空间
} vector;

//初始化
vector *init_vector(int n)
{
    vector *p = (vector *)malloc(sizeof(vector));
    p->size = n;
    p->count = 0;
    p->data = (int *)malloc(sizeof(int) * n);
    return p;
}

void clear(vector *v)
{
    if (v == NULL)
        return;
    free(v->data);
    free(v);
    return;
}

int expand(vector *v) //阔容
{
    if (v == NULL)
        return 0;
    int *temp = (int *)realloc(v->data, sizeof(int) * 2 * v->size); //第一个参数是从哪里开始扩容  第二个参数是扩容多大
    if (temp == NULL)
        return 0; //内存不足 扩容失败
    v->data = temp;
    // realloc 对data重新分配内存
    v->size *= 2;
    printf("expand v from %d to %d", v->size / 2, v->size);
    return 1;
}

int insert(vector *v, int pos, int val)
{
    if (pos > v->count || pos < 0)
        return 0;
    if (v->size == v->count && !expand(v))
        return 0;
    //&& 当v->size == v->count  为false时会跳过后面的expend
    //当前面为true时 会执行 expend
    //但当expend扩容失败时 才会return0
    //--------------这一行代码可以顶我很多行了  wuwuwuwuwu----

    for (int i = v->count - 1; i >= pos; i--)
    {
        v->data[i + 1] = v->data[i];
    }
    v->data[pos] = val;
    v->count++;
    return 1;
}

int erase(vector *v, int pos)
{
    if (pos >= v->count || pos < 0)
        return 0;
    for (int i = pos; i < v->count - 1; i++)
    {
        v->data[i] = v->data[i + 1];
    }
    v->count--;
    return 1;
}

void printf_vector(vector *v)
{
    int len = 0;
    for (int i = 0; i < v->size; i++)
    {
        // len 表示总共输出的长度
        len += printf("%3d", i); //%5d 表示使此输出值占5个空
    }

    printf("\n");
    for (int i = 0; i < len; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i < v->count; i++)
    {
        printf("%3d", v->data[i]);
    }
    printf("\n");
    printf("\n");
    printf("\n");
    return;
}

int main()
{
    srand(time(0));
    int Max_op = 20;
    vector *v = init_vector(2);
    for (int i = 0; i < Max_op; i++)
    {
        int op = rand() % 4; //在0 1 2 3中随机
        int pos, val, ret;
        switch (op)
        {
        case 0:
        case 1:
        case 2: // op为0 1 2 时执行下列语句
            pos = rand() % (v->count + 2);
            val = rand() % 100;
            ret = insert(v, pos, val); // ret表示操作是否成功
            printf("insert %d at %d to vector = %d\n", val, pos, ret);
            break;

        case 3:
            pos = rand() % (v->count + 2);
            ret = erase(v, pos);
            printf("erase item at %d in vector = %d\n", pos, ret);
            break;
        }
        printf_vector(v);
    }

    system("pause");
    return 0;
}