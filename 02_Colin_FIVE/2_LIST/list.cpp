#include <iostream>
#include <time.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;

Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->data = key;
    return p;
}

//返回值是Node*
Node *push_back(Node *head, int key)
{
    if (head == NULL)
    {
        return head = getNewNode(key);
    }
    Node *p = getNewNode(key);
    Node *q = head;

    while (q->next)
        q = q->next;
    q->next = p;
    return head;
}
// head = push_back2(head, a);

//返回值是void
void push_back2(Node *&head, int key)
{
    if (head == NULL)
    {
        head = getNewNode(key);
        return;
    }
    else
    {
        Node *p = getNewNode(key);
        Node *q = head;
        while (q->next)
            q = q->next;
        q->next = p;
        return;
    }
}
// push_back2(head, a);

Node *push_front(Node *head, int key)
{
    if (head == NULL)
        return head = getNewNode(key);

    Node *p = getNewNode(key);
    p->next = head;
    head = p;
    return head;
}

void output(Node *head)
{
    if (head == NULL)
    {
        cout << "链表为空" << endl;
        return;
    }
    Node *p = head;
    cout << "正序输出：";
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
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
    }
}

void FanZhuanPrintf(Node *head)
{
    if (head->next == NULL)
    {
        cout << "逆序输出：" << head->data << " ";
        return;
    }
    FanZhuanPrintf(head->next);
    cout << head->data << " ";
    return;
}

Node *FanZhuan(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *newHead = head; //头
    Node *p = head->next;
    Node *q = p->next; //拿  断
    newHead->next = NULL;

    while (q)
    {
        p->next = newHead;
        newHead = p;
        p = q;
        q = q->next;
    }
    p->next = newHead;
    newHead = p;
    return newHead;
}

Node *Link(Node *h1, Node *h2)
{
    if (h1 == NULL && h2 != NULL)
        return h2;
    if (h1 != NULL && h2 == NULL)
        return h1;

    Node *p1 = h1;
    Node *p2 = h2;
    Node newHead;

    Node *q = &newHead;
    while (p1 && p2)
    {
        if (p1->data > p2->data)
        {
            q->next = p2;
            p2 = p2->next;
            q = q->next;
        }
        else
        {
            q->next = p1;
            p1 = p1->next;
            q = q->next;
        }
    }

    if (p1 == NULL)
        q->next = p2;

    if (p2 == NULL)
        q->next = p1;
    return newHead.next;
}

void push_back3(Node **head, int data)
{
    if (*head == NULL)
    {
        *head = getNewNode(data);
        return;
    }
    Node *p = getNewNode(data);
    Node *q = *head;
    while (q->next != NULL)
        q = q->next;
    q->next = p;
    return;
}

int main()
{
    srand(time(0));
    /*
        int a;
        Node *head = NULL;
        for (int i = 0; i < 5; i++)
        {
            cin >> a;
            push_back3(&head, a);
        }
        output(head);
        cout << endl;
    */
    /*
    FanZhuanPrintf(head);
    cout << endl;
    cout << endl;

    head = FanZhuan(head);
    output(head);
    cout << endl;
    */

    Node *h1 = NULL;
    Node *h2 = NULL;
    int x = 0;
    int y = 0;
    for (int i = 0; i < 5; i++)
    {
        x += rand() % 5;
        y += rand() % 5;
        push_back2(h1, x);
        push_back2(h2, y);
    }
    output(h1);
    printf("\n");

    output(h2);
    printf("\n");

    h1 = Link(h1, h2);
    output(h1);
    printf("\n");

    // clear(head);
    system("pause");
    return 0;
}