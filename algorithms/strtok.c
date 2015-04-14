#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mymemset(void *s, int ch, int n)
{
    int i;
    for(i=0; i<n; ++i,++s)
        *(int*)s = ch;
    return 0;
}

int mystrlen(const char *str)
{
    int length;
    for(length=0; *str; ++length, ++str)
        /* do nothing */;
    return length;
}

size_t linuxstrlen(const char *s)
{
	int i = 0;
	while (s[i++]);
	return i-1;
}

void* mymemcpy(void *dest, const void *src, size_t count)
{
    int i;
    for(i=0; i<count; ++i, ++dest, ++src)
        *(int*)dest = *(int*)src;
    return 0;
}

void *mymemmove(void *dest, const void *src, size_t n)
{
}

char *mystrdup(char *s)
{
    char *tmp = (char*)malloc(mystrlen(s));
    return tmp;
}

char *mystrcat(char *dest, const char *src)
{
    int i;
    int len = mystrlen(dest);
    for(i=len; src[i-len]; ++i)
        dest[i] = src[i-len];
    return dest;
}

char *mystrtok(char *str, const char *delim)
{
    char *head = str;
    static char *saver;
    if(str)
        saver = str;
    else
        head = saver;
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

char *mystrtok_r(char *str, const char *delim, char **saveptr)
{
    char * head = str;
    if(! *str)
        return NULL;
    for(; *str!=*delim; ++str) {
        if(! *(str+1)) {
            ++str;
            break;
        }
    }
    while(*str == *delim) {
        *str = '\0';
        ++str;
    }
    *saveptr = str;
    return head;
}

int parse_url(char *url, char **buffer)
{
    int i = 0;
    char *saveptr = NULL;
    //char *result = mystrtok(url, "?");
    char *result = mystrtok_r(url, "?", &saveptr);
    if(result == NULL)
        printf("NULL\n");

    while(1) {
        buffer[i] = malloc(100);
        memset(buffer[i], 0, 100);
        //result = mystrtok(NULL, "&");
        result = mystrtok_r(saveptr, "&", &saveptr);
        if(result == NULL)
            break;
        memcpy(buffer[i++], result, strlen(result));
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
   // char *buffer[100];
   // char *url_buffer = (char*)malloc(100);
   // char *url = "http://www.google.cn/search?complete=1&hl=zh-CN&ie=GB2312&q=linux&meta=&test=x";
   // char *url2 = "http://www.baidu.com/s?wd=linux&cl=3";
   // memmove(url_buffer, url, strlen(url));
   // int number = parse_url(url_buffer, buffer);
   // int i;
   // for(i=0; i<number; ++i)
   //     printf("result is %s\n", buffer[i]);
   // release_url(buffer, number);
   // printf("\n*********\n");

   // mymemset(url_buffer, 0, strlen(url));
   // memmove(url_buffer, url2, strlen(url2));
   // number = parse_url(url_buffer, buffer);
   // for(i=0; i<number; ++i)
   //     printf("result is %s\n", buffer[i]);
   // release_url(buffer, number);
    return 0;
}
