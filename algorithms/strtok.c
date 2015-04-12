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
    if(! *saver)
        return NULL;
    for(; *saver!=*delim; ++saver) {
        if(! *(saver+1)) {
            ++saver;
            break;
        }
    }
    while(*saver == *delim) {
        *saver = '\0';
        ++saver;
    }
    return head;
}

int parse_url(char *url, char **buffer)
{
    int i = 0;
    char *result = mystrtok(url, "?");
    if(result == NULL)
        printf("NULL\n");

    while(1) {
        buffer[i] = malloc(100);
        result = mystrtok(NULL, "&");
        if(result == NULL)
            break;
        memmove(buffer[i++], result, strlen(result));
    }
    return i;
}

void release_url(char **buffer, int num)
{
    int i;
    for(i=0; i<num; ++i)
        free(buffer[i]);
}

int main(void)
{
    char *buffer[10];
    char *url_buffer = (char*)malloc(100);
    char *url = "http://www.google.cn/search?complete=1&hl=zh-CN&ie=GB2312&q=linux&meta=&test=x";
    memmove(url_buffer, url, strlen(url));
    int number = parse_url(url_buffer, buffer);
    int i;
    for(i=0; i<number; ++i)
        printf("result is %s\n", buffer[i]);
    release_url(buffer, number);
    printf("\n*********\n");

    memset(url_buffer, 0, strlen(url));
    char *url2= "http://www.baidu.com/s?wd=linux&cl=3";
    memmove(url_buffer, url2, strlen(url2));
    number = parse_url(url_buffer, buffer);
    release_url(buffer, number);
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
