#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char *data;
    int cnt;
    int idx;
    struct node *next;
} Node;

Node *head = NULL;

// void add(Node *list, char *word)
// {
//     Node *tmp = (Node *)malloc(sizeof(Node));
//     tmp->data = strdup(word);
//     Node *f = head->next;
//     while (f != NULL)
//     {
//         if (strcmp(f->data, word) < 0)
//             continue;
//         else if (strcmp(f->data, word) > 0)
//         {
//             tmp->next = f;
//         }
//         f = f->next;
//     }
// }
// Node *find(char *word)
// {
//     Node *f = head->next;
//     while (f != NULL)
//     {
//         if (strcmp(f->data, word) == 0)
//         {
//             return f;
//         }
//     }
//     return NULL;
// }
int addAfter(Node *list, char word)
{
    if (list == NULL)
    {
        return 0;
    }
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = strdup(word);
    tmp->next = list->next;
    list->next = tmp;
    return 1;
}
void addFirst(Node *list, char *item)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = strdup(item);
    tmp->next = list->next;
    list->next = tmp;
}
int add(int idx, char *word)
{
    if (idx < 0)
    {
        return 0;
    }
    if (idx == 0)
    {
        addFirst(head, word);
        return 1;
    }
    Node *prev = get_node(idx - 1);
    if (prev != NULL)
    {
        addAfter(prev, word);
        return 1;
    }
    return 0;
}
void add_to_ordered_list(char *word)
{
    Node *p = head;
    Node *q = NULL;
    while (p != NULL && strcmp(p->data, word) <= 0)
    {
        q = p;
        p = p->next;
    }
    if (q == NULL)
    {
        addFirst(p, word);
    }
    else
    {
        addAfter(q, word);
    }
}
int main()
{
    FILE *fp = fopen("harry2.txt", "r");
    if (fp == NULL)
    {
        return 0;
    }
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    char w[100];
    while (!feof(fp))
    {
        // Node *word = (Node *)malloc(sizeof(Node));
        fscanf(fp, "%s", w);
        add_to_ordered_list(w);
    }
    fclose(fp);
    Node *curr = head->next;
    while (curr != NULL)
    {
        printf("%s ", curr->data);
        curr = curr->next;
    }
    return 0;
}