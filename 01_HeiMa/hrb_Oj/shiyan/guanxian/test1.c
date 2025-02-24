#include <stdio.h>
#include <stdlib.h>
typedef struct block
{
    int size;
    int start;
    int loc;
    struct block *next;
    struct block *prior;
} block;
struct block *prior;

int maxsize = 512;
block *note;
block *id[10];
void printmem()
{
    int i;
    for (i = 9; i >= 0; i--)
    {
        printf("%d  ->", i);
        block *temp = (struct block *)malloc(sizeof(struct block));
        temp = id[i]->next;
        while (temp != NULL)
        {
            printf("%d(%s)(%d)->", temp->size, temp->loc == 1 ? "占用" : "空闲", temp->start);
            temp = temp->next;
        }
        printf("\n");
    }
}
void init()
{
    int i;
    for (i = 0; i < 9; i++)
    {
        id[i] = (struct block *)malloc(sizeof(struct block));
        id[i]->prior = id[i];
        id[i]->next = NULL;
    }
    note = (struct block *)malloc(sizeof(struct block));
    note->size = maxsize;
    note->start = 0;
    note->loc = 0;
    note->next = NULL;
    id[9] = (struct block *)malloc(sizeof(struct block));
    id[9]->next = note;
    id[9]->prior = id[9];
    note->prior = id[9];
    printmem();
}
int power(int x, int y)
{
    int k = 0, tmp = 1;
    for (; k < y; k++)
    {
        tmp = tmp * x;
    }
    return tmp;
}
int root(int x, int y)
{
    int result = y, count = 0;
    while (result != 1)
    {
        result = result / x;
        count++;
    }
    return count;
}
int split(int tempId)
{
    block *pend = (struct block *)malloc(sizeof(struct block));
    block *cend = (struct block *)malloc(sizeof(struct block));
    block *newf = (struct block *)malloc(sizeof(struct block));
    block *newu = (struct block *)malloc(sizeof(struct block));
    pend = id[tempId]->next;
    int flag = 0, isFirst = 0;
    while (pend != NULL)
    {
        if (pend->loc == 0)
        {
            if (isFirst == 0)
            {
                id[tempId]->next = pend->next;
            }
            else
            {
                pend->prior->next = pend->next;
            }
            int size = (pend->size) / 2;
            int start = pend->start;
            newu->size = size;
            newu->start = start;
            newf->start = start + size;
            newu->loc = 0;
            newf->size = size;
            newf->loc = 0;
            newf->prior = newu;
            newu->next = newf;
            newf->next = NULL;
            tempId--;
            cend = id[tempId];
            while (cend->next != NULL)
            {
                cend = cend->next;
            }
            cend->next = newu;
            newu->prior = cend;
            flag = 1;
            return 1;
        }
        else
        {
            pend = pend->next;
            isFirst++;
        }
    }
    if (flag == 0)
    {
        tempId = tempId + 1;
        if (tempId <= 9)
        {
            free(pend);
            free(cend);
            free(newu);
            free(newf);
            split(tempId);
        }
        else
        {
            return -1;
        }
    }
}
int merge(int tempId, block *first)
{
    block *merger = (struct block *)malloc(sizeof(struct block));
    block *second = NULL;
    second = id[tempId]->next;
    int nextStart = first->start + first->size;
    int preStart = first->start - first->size;
    int flag = 0, isFirst = 0;
    while (second != NULL)
    {
        if ((second->start == nextStart || second->start == preStart) && second->loc == 0)
        {
            merger->size = (first->size) + (second->size);
            merger->loc = 0;
            merger->start = (first->start) < (second->start) ? (first->start) : (second->start);
            if (first->next != NULL)
            {
                first->next->prior = first->prior;
            }
            if ((first->prior->prior) == first->prior)
            {
                id[tempId]->next = first->next;
            }
            else
            {
                first->prior->next = first->next;
            }
            if (second->next != NULL)
            {
                second->next->prior = second->prior;
            }
            if (isFirst == 0)
            {
                id[tempId]->next = second->next;
            }
            else
            {
                second->prior->next = second->next;
            }
            tempId++;
            merger->next = id[tempId]->next;
            merger->prior = id[tempId];
            if (id[tempId]->next != NULL)
                id[tempId]->next->prior = merger;
            id[tempId]->next = merger;
            if (tempId < 9)
            {
                merge(tempId, merger);
            }
            else
            {
                return 0;
            }
            return 1;
        }
        else
        {
            second = second->next;
            isFirst++;
        }
    }
    return 1;
}
int freeb(int size)
{
    block *first = (struct block *)malloc(sizeof(struct block));
    int tempId = root(2, size);
    first = id[tempId]->next;
    int flag = 0;
    while (first != NULL)
    {
        if (first->loc == 1)
        {
            first->loc = 0;
            flag = 1;
            break;
        }
        else
        {
            first = first->next;
        }
    }
    if (flag == 1)
    {
        merge(tempId, first);
        printmem();
    }
    else
    {
        printf("需要释放的内存块不存在!\n");
    }
    return 1;
}
int requestb(int size)
{
    block *temp = (struct block *)malloc(sizeof(struct block));
    int tempId = root(2, size);
    int flag = 0;
    temp = id[tempId]->next;
    while (temp != NULL)
    {
        if (temp->loc == 0 && temp->size == size)
        {
            temp->loc = 1;
            flag = 1;
            printf("分配成功!\n");
            printmem();
            return 1;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (flag == 0)
    {
        tempId++;
        if (tempId <= 9)
        {
            int rs = split(tempId);
            if (rs == -1)
            {
                printf("没有合适的空间可分配!\n");
                return -1;
            }
            else
            {
                requestb(size);
            }
        }
        else
        {
            printf("没有合适的空间可分配!\n");
            return -1;
        }
    }
    free(temp);
}
int main()
{
    init();
    int flag = 1;
    int size;
    char order;
    do
    {
        printf("请输入命令:(以空格相隔,示例:r 8)\n");
        scanf("%c %d", &order, &size);
        if (order == 'r')
        {
            requestb(size);
        }
        else if (order == 'f')
        {
            freeb(size);
        }
        else
        {
            printf("error!");
        }
        printf("是否继续?(1继续，0退出):");
        scanf("%d", &flag);
        getchar();
    } while (flag == 1);
}


