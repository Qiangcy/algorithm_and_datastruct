#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *mystrtok_r(char *str, const char *delim, char **saveptr)
{
}

char *mystrtok(char *str, const char *delim)
{
    static char *saver;
    char *head = str;
    if(str != NULL)
        saver = str;
    else
        head = saver;
    int i=0;
    printf("str is %s \n", str);
    for(; *saver!=*delim; ++saver) {
        printf("saver is %c\n", *saver);
        if(! *saver) {
            printf("return NULL!!\n");
            return NULL;
        }
    }
    //while(*saver == *delim) {
    //    *saver = '\0';
        //++saver;
    //}
    printf("in5\n");
    return head;
}

void *parse_url(char *url, char **buffer)
{
    int i = 0;
    printf("in 1\n");
     if( mystrtok(url, "?") == NULL)
         printf("NULL\n");
//    printf("in 2\n");
//     buffer[i++] = malloc(100);
//     *buffer[i++] = *mystrtok(url, "?");
//    printf("%s\n", *buffer[0]);
//    while ( (*buffer[i++] = mystrtok(NULL, "&")) != NULL) {
//        char c;
//        scanf("%c", &c);
//        printf("%s\n", *buffer[i]);
//    }
}

int main(void)
{
    char *buffer[10];
    //char *url = (char*)malloc(100);
    char *url = "http://www.google.cn/search?complete=1&hl=zh-CN&ie=GB2312&q=linux&meta=";
    parse_url(url, buffer);
    return 0;
}

/* strtok_r test
int main(int argc, char *argv[])
{
    char *str1, *str2, *token, *subtoken;
    char *saveptr1, *saveptr2;
    int j;
    if (argc != 4) {
        fprintf(stderr, "Usage: %s string delim subdelim\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (j = 1, str1 = argv[1]; ; j++, str1 = NULL)
    {
        token = strtok_r(str1, argv[2], &saveptr1);
        if (token == NULL)
            break;
        printf("%d: %s\n", j, token);
        for (str2 = token; ; str2 = NULL) {
            subtoken = strtok_r(str2, argv[3], &saveptr2);
            if (subtoken == NULL)
                break;
            printf(" --> %s\n", subtoken);
        }
    }
    exit(EXIT_SUCCESS);
}
*/

/* test of strtok
   int main(void)
   {
   char str[] = "root:x::0:root:/root:/bin/bash:";
   char *token;
   token = mystrtok(str, ":");
   printf("%s\n", token);
   while ( (token = mystrtok(NULL, ":")) != NULL) {
//        char c;
//        scanf("%c", &c);
printf("%s\n", token);
}
return 0;

}
*/
