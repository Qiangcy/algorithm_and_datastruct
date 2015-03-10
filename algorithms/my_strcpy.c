#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strcpy(char *dest, const char*src)
{
    char *temp = dest;
    while((*dest++ = *src++) != '\0')
        /* do nothing */;
    return temp;
}

static inline bool is_space(char c)
{
    if(c==' ' || c=='\t' || c=='\n' || c=='\r')
        return true;
    else
        return false;
}

char *shrink_space(char *dest, const char *src, size_t n)
{
    size_t i, j;
    for(j=0,i=0; i<n && src[i]!='\0'; ++i) {
        if(is_space(src[i]) && is_space(src[i+1])) {
            continue;
        }else {
            dest[j] = src[i];
            ++j;
        }
    }
    for(; i<n; ++i)
        dest[i] = '\0';
    return dest;
}

int main()
{
    int i;
    char buf[] = "-a b   c   d     e  \t      \n f     \t\t            ghij";
    char *dest = (char*)malloc(100);
    printf("buf is %s", shrink_space(dest, buf, 100));
}
