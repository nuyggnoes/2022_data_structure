#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char *data;
    int cnt;
    struct node *next;
} Node;
Node *head = NULL;
void addFirst(char *word)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = strdup(word);
    tmp->next = head->next;
    head->next = tmp;
}
int addAfter(Node *prev, char *word)
{
    if (prev == NULL)
    {
        return 0;
    }
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = strdup(word);
    tmp->next = prev->next;
    prev->next = tmp;
    return 1;
}
void add_to_ordered_list(char *word)
{
    Node *p = head->next;
    Node *q = NULL;
    while (p != NULL && strcmp(p->data, word) <= 0)
    {
        q = p;
        p = p->next;
    }
    if (q == NULL)
    {
        addFirst(word);
    }
    else
    {
        addAfter(q, word);
    }
}
int dup(char *word)
{
    Node *curr = head->next;
    while (curr != NULL)
    {
        if (strcmp(curr->data, word) == 0)
        {
            curr->cnt++;
            return 0;
        }
        curr = curr->next;
    }
    return 1;
}
Node *delete (Node *prev, Node *curr)
{
    prev->next = curr->next;
    return prev->next;
}
void replace(Node *prev, Node *curr)
{
}
int total = 0;
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
    int flag = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%s", w);
        flag = dup(w);
        if (flag == 0)
            continue;
        else
        {
            add_to_ordered_list(w);
        }
    }
    fclose(fp);
    Node *p = head->next;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->cnt + 1 > 10)
        {
            // printf("%s: %d\n", p->data, p->cnt + 1);
            total++;
            q = p;
            p = p->next;
        }
        else
        {
            p = delete (q, p);
        }
    }
    Node *cur = head;
    Node *cy = cur->next;
    int count = total;
    while (count > 0)
    {
        cur = head;
        cy = cur->next;
        while (cy != NULL)
        {
            if (cur->cnt < cy->cnt)
            {
                while (1)
                {
                    if (cur->cnt >= cy->next->cnt)
                    {
                        break;
                    }
                    cy = cy->next;
                }
                head->next = cur->next;
                cur->next = cy->next;
                cy->next = cur;
            }
            else
            {
                cy = cy->next;
            }
        }
        count--;
    }

    p = head->next;
    while (p != NULL)
    {
        printf("%s: %d\n", p->data, p->cnt);
        p = p->next;
    }
    printf("%d", total);
    return 0;
}