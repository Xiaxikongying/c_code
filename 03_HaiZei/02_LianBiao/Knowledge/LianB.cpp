#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *init_Node(int val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

void clear(Node *head)
{
    if (head == NULL)
        return;
    Node *q;
    for (Node *p = head; p != NULL; p = q)
    {
        q = p->next;
        free(p);
        // q指向p的下一个节点  销毁p  然后p=q
        // q又指向p的下一个节点  循环......
    }
    return;
}

Node *insert(Node *head, int pos, int val)
{
    if (pos == 0) //在head之前插入元素
    {
        Node *p = init_Node(val);
        p->next = head;
        return p;
        // p成为新的head节点
    }
    Node *p = head;
    for (int i = 1; i < pos; i++)
    {
        // p从head向前走pos-1步
        //到达pos前一个节点
        p = p->next;
    }
    Node *node = init_Node(val); //待插入的节点
    node->next = p->next;
    p->next = node;
    return head;
}

void print_List(Node *head, int flag)
{
    if (head == NULL)
        return;
    int n = 0;
    for (Node *p = head; p != NULL; p = p->next)
        n++;
    for (int i = 0; i < n; i++)
    {
        printf("%3d", i);
        printf("  ");
    }
    printf("\n");

    for (Node *p = head; p != NULL; p = p->next)
    {
        printf("%3d", p->data);
        printf("->");
    }
    printf("  NULL\n");
    if (flag == 0)
        printf("\n\n\n");
    return;
}

int find(Node *head, int val)
{
    Node *p = head;
    int n = 0;
    while (p)
    {
        if (p->data == val)
        {
            print_List(head, 1);
            int len = n * (3 + 2) + 1; // 3是字符占位  2是箭头占位  +1是为了更准确指向数字
            for (int i = 0; i < len; i++)
                printf(" ");
            printf("↑\n");

            /*
            //拼接箭头
            for (int i = 0; i < len; i++)
                printf(" ");
            printf("^\n");
            for (int i = 0; i < len; i++)
             printf(" ");
            printf("|\n");
            */

            return 1;
        }
        p = p->next;
        n++;
    }
    return 0;
}

#define Max_op 7

int main()
{
    srand(time(0));
    Node *head = NULL;
    for (int i = 0; i < Max_op; i++)
    {
        int val = rand() % 100;
        int pos = rand() % (i + 1);
        printf("insert %d at %d to linkList\n", val, pos);
        head = insert(head, pos, val);
        print_List(head, 0);
    }

    int val;
    while (~scanf("%d", &val))
    {
        // 意思就是当有值输入的时候，进入while，当没有值输入时就结束while。
        if (!find(head, val))
        {
            printf("not found\n");
        }
        if (val < 0)
            break;
    }
    clear(head);
    system("pause");
    return 0;
}