#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char *word;
    int cnt;
    struct node *next;
} Node;
Node *head = NULL;
int main()
{
    FILE *fp = fopen("harry2.txt", "r");
    if (fp == NULL)
        return 0;
    char buf[30];
    while (fscanf(fp, "%s", buf) != NULL)
    {
        Node *p = head;
        while (p != NULL && strcmp(p->word, buf) != 0)
            p = p->next;
        if (p != NULL)
            p->cnt++;
        else
        {
            Node *tmp = (Node *)malloc(sizeof(Node));
            tmp->word = strdup(buf);
            tmp->cnt = 1;
            tmp->next = NULL;
        }
    }
    fclose(fp);
    return 0;
}