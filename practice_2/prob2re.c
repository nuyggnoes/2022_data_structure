// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>
// int main()
// {
//     FILE *fp = fopen("harry.txt", "r");
//     char *data[10000];
//     char buffer[40];
//     int n = 0;
//     while (fscanf(fp, "%s", buffer) != EOF) //파일의 끝까지 buffer에 단어를 저장
//     {
//         bool flag = true;
//         for (int i = 0; i < n; i++)
//         {
//             if (strcmp(buffer, data[i]) == 0) //파일에서 읽어온 단어가 이미 있는 단어인 경우
//             {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag) //새로운 단어인 경우
//         {
//             int j = n - 1;
//             while (j >= 0 && strcmp(buffer, data[j]) < 0) //사전식 순서로 정렬
//             {
//                 data[j + 1] = data[j]; //이미 있는 더 큰 단어를 뒤로 보냄
//                 j--;
//             }
//             data[j + 1] = strdup(buffer); //중간에 읽어온 단어를 넣음
//             n++;                          //단어 개수 증가
//         }
//     }
//     fclose(fp);
//     char pre[40];
//     scanf("%s", pre);
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (strncmp(pre, data[i], strlen(pre)) == 0)
//         {
//             printf("%s\n", data[i]);
//             cnt++;
//         }
//     }
//     printf("%d", cnt);
//     return 0;
// }