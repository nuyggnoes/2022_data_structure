#include <stdio.h>
#include <stdlib.h>
#define LEN 10000
typedef struct node
{
    // char *data;
    // int cnt;
    int data;
    struct node *next;
} Node;

Node *head = NULL;
void addFirst(Node *target, int data)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->next = target->next;
    newnode->data = data;
    target->next = newnode;
}
int main()
{
    // FILE *fp = fopen("harry.txt", "r");

    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    addFirst(head, 10);
    addFirst(head, 20);
    addFirst(head, 30);
    Node *curr = head->next;
    while (curr != NULL)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    curr = head->next;
    while (curr != NULL)
    {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    // fclose(fp);
    return 0;
}