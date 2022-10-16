// 테스트 데이터를 모두 통과했습니다.
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
Node *head2 = NULL;

void addFirst(char *word)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->cnt = 1;
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
    tmp->cnt = 1;
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
    head2 = (Node *)malloc(sizeof(Node));
    head2->next = NULL;
    char word[100];
    int flag = 0;
    while (!feof(fp))
    {

        fscanf(fp, "%s", word);
        flag = dup(word);
        if (flag == 0)
            continue;
        else
        {
            add_to_ordered_list(word);
        }
        total++;
    }
    fclose(fp);
    Node *curr = head->next;
    while (curr != NULL)
    {
        printf("%s: %d\n", curr->data, curr->cnt);
        curr = curr->next;
    }
    printf("%d\n", total);
    int total1 = total;
    Node *k = head->next;
    while (k != NULL)
    {
        Node *tmp = k->next;
        if (tmp == NULL)
        {
            break;
        }
        else if (tmp->cnt <= 10)
        {
            total1--;
            k->next = tmp->next;
        }
        else
        {
            k = k->next;
        }
    }
    Node *p2 = head->next;
    while (p2 != NULL)
    {
        printf("%s: %d\n", p2->data, p2->cnt);
        p2 = p2->next;
    }
    printf("%d\n", total1);
    int max = 0;
    Node *fmax = head->next;
    while (fmax != NULL)
    {
        if (fmax->cnt > max)
        {
            max = fmax->cnt;
        }
        fmax = fmax->next;
    }
    Node *c = head2;
    while (max != 10)
    {
        Node *cy = head->next;
        while (cy != NULL)
        {
            Node *tmp = cy->next;
            if (tmp == NULL)
            {
                break;
            }
            else if (tmp->cnt == max)
            {
                c->next = tmp;
                c = c->next;
                cy->next = tmp->next;
            }
            else
            {
                cy = cy->next;
            }
        }
        max--;
    }
    Node *p3 = head2->next;
    while (p3 != NULL)
    {
        printf("%s: %d\n", p3->data, p3->cnt);
        p3 = p3->next;
    }
    printf("%d", total1);
    return 0;
}