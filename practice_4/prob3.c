#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *del_even(Node *head)
{
    int cnt = 0;
    Node *p = head;
    Node *q = NULL;
    while (p != NULL)
    {
        cnt++;
        if (cnt % 2 == 0)
        {
            q->next = p->next;
            p = p->next;
            continue;
        }
        q = p;
        p = p->next;
    }
    return head;
}

Node *createNode(int num);
Node *makeListFromArray(int n, int data[], Node *head);
void printList(Node *h);
int main()
{
    int node1[] = {1, 2, 3, 4, 5, 6};
    Node *head = NULL;
    head = makeListFromArray(sizeof(node1) / sizeof(node1[0]), node1, head);
    head = del_even(head);
    printList(head);
}

Node *createNode(int num)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = num;
    p->next = NULL;
    return p;
}

Node *head = NULL;

Node *makeListFromArray(int n, int data[], Node *head)
{
    Node *read = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        Node *p = createNode(data[i]);
        p->next = head;
        head = p;
    }
    return head;
}

void printList(Node *h)
{
    while (h != NULL)
    {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}