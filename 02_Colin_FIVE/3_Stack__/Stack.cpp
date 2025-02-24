#include <iostream>
#include <time.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->data = key;
    return p;
}

Node *push(Node *head, int key)
{
    if (head == NULL)
        return getNewNode(key);
    Node *p = getNewNode(key);
    p->next = head;
    head = p;
    return head;
}

Node *pop(Node *head)
{
    if (head == NULL)
        return head;
    Node *p = head;
    head = head->next;
    free(p);
    p = NULL;
    return head;
}
int getTop(Node *head)
{
    return head->data;
}

void output(Node *head)
{
    if (head == NULL)
    {
        cout << "链表为空" << endl;
        return;
    }
    Node *p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    srand(time(0));
    int a;
    for (int i = 0; i < 8; i++)
    {
        a = rand() % 50;
        head = push(head, a);
    }
    output(head);

    head = pop(head);
    output(head);
    head = pop(head);
    output(head);

    cout << getTop(head) << endl;

    system("pause");
    return 0;
}