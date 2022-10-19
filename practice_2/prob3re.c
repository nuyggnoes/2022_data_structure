// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>
// int main()
// {
//     FILE *fp = fopen("harry.txt", "r");
//     char *data[10000];
//     int cnt[10000] = {
//         0,
//     };
//     char input[40];
//     int n = 0;
//     while (fscanf(fp, "%s", input) != EOF)
//     {
//         if (strlen(input) < 6)
//             continue;
//         bool flag = true;
//         for (int i = 0; i < n; i++)
//         {
//             if (strcmp(input, data[i]) == 0)
//             {
//                 flag = false;
//                 cnt[i]++;
//                 break;
//             }
//         }
//         if (flag)
//         {
//             int j = n - 1;
//             while (j >= 0 && strcmp(input, data[j]) < 0)
//             {
//                 data[j + 1] = data[j];
//                 cnt[j + 1] = cnt[j];
//                 j--;
//             }
//             data[j + 1] = strdup(input);
//             cnt[j + 1] = 1;
//             n++;
//         }
//     }
//     fclose(fp);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%s : %d\n", data[i], cnt[i]);
//     }
//     printf("%d", n);
//     return 0;
// }