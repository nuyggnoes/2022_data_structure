#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int day, month, year;
    struct node *next;
} Node;

Node *head = NULL;

void printf_list()
{
    Node *p = head;
    while (p != NULL)
    {
        printf("%d %d %d\n", p->year, p->month, p->day);
        p = p->next;
    }
}
void read_file()
{
    // char buf[20];
    // // FILE *fp = fopen("date.txt", "r");
    // Node *tmp = (Node *)malloc(sizeof(Node));

    // // while (fgets(buf, 20, fp) != NULL)
    // // {
    // // char *pstr = fgets(buf, 20, fp);
    // // if (buf[strlen(buf) - 1] == '\n')
    // // {
    // // buf[strlen(buf) - 1] = '\0';
    // // }
    // // if (strlen(buf) <= 0)
    // // continue;
    // // char *ptr = strtok(buf, " ");
    // // tmp->day = *strdup(ptr) - 48;
    // tmp->day = 1;
    // // ptr = strtok(NULL, " ");
    // // tmp->month = *strdup(ptr) - 48;
    // tmp->month = 2;
    // // ptr = strtok(NULL, " ");
    // // tmp->year = *strdup(ptr) - 48;
    // tmp->year = 3;
    // // tmp = tmp->next;
    // // }
    // tmp->next = head->next;
    // head->next = tmp;
    // // date.txt 파일을 읽어서 날짜들을 파일에 저장된 순서대로
    // // head가 가리키는 연결리스트에 저장한다.
    // // fclose(fp);
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->day = 1;
    tmp->month = 2;
    tmp->year = 3;
    tmp->next = head->next;
    head->next = tmp;
}
void sort_list()
{
    // head가 가리키는 연결리스트를 시간순으로 정렬한다.
}
int main()
{
    read_file();
    printf_list();
    printf("\n");
    // sort_list();
    // printf_list();
    return 0;
}