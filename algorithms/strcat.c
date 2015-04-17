#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrcat(char *dest, char *src)
{
    int i, j;
    for(i=0; dest[i]; ++i)
        /* do nothing */;
    for(j=0; src[j]; ++j, ++i)
        dest[i] = src[j];
    return dest;
}

char *mystrncat(char *dest, char *src, int n)
{
    int i, j;
    for(i=0; dest[i]; ++i)
        /* do nothing */;
    for(j=0; j<n; ++j, ++i)
        dest[i] = src[j];
    return dest;
}

int mystrcmp(const char *lhs, const char *rhs)
{
    int res;
    for(; *lhs&&*rhs; ++lhs, ++rhs)
        if((res = *lhs - *rhs) != 0)
            break;
    return res;
}

int linuxstrcmp(const char *cs, const char *ct)
{
    signed char __res;
    while (1) {
        if ((__res = *cs - *ct++) != 0 || !*cs++)
            break;
    }
    return __res;
}

int mymemcmp(const void *buf1, const void *buf2, unsigned int count)
{
    /* linux implementation */
    const char *p1, *p2;
    int res = 0;
    for(p1=(char*)buf1, p2=(char*)buf2; count>(unsigned int)0; ++p1, ++p2, --count)
        if((res = *p1 - *p2) != 0)
            break;
    return res;
    /*
       my implementation.
       unsigned int i = 0;
       while((((char*)buf1)[i] == ((char*)buf2)[i]) && i<=count)
       ++i;
       if(((char*)buf1)[i] > ((char*)buf2)[i])
       return 1;
       else if(((char*)buf1)[i] < ((char*)buf2)[i])
       return -1;
       else
       return 0;
       */
}

char *mystrchr(const char* _Str,int _Val)
{
    while(*_Str++) {
        if(*_Str == _Val)
            return (char*)_Str;
    }
    return NULL;
}

char *mystrrchr(const char* _Str,int _Val)
{
    const char* head = _Str;
    while(*_Str++)
        ;
    --_Str;
    while((*--_Str) && _Str!=head) {
        if(*_Str == _Val)
            return (char*)_Str;
    }
    return NULL;
}

void print(int r)
{
    printf("\n**** new *** \n");
    if(!r)
        printf("s1 and s2 are identical\n");/*s1等于s2*/
    else if(r < 0)
        printf("s1 is less than s2\n");/*s1小于s2*/
    else
        printf("s1 is greater than s2\n");/*s1大于s2*/
}

int main(void)
{
    printf("\n\n");
    char string[17];
    char *ptr,c='r';
    char d[20]="GoldenGlobal";
    char *s="View";
    char *s1 = "Hello,Programmer";
    char *s2 = "Hello,Programmer!";
    int r;
    strcpy(string,"Thisisastring");
    ptr=mystrrchr(string,c);
    if(ptr)
        printf("The character %c is at position:%s\n" , c, ptr);
    else
        printf("The character was notfound\n");

    printf("\nfinish\n");


    mystrcat(d,s);
    printf("%s\n", d);

    mystrncat(d,s,2);
    printf("%s",d);
    printf("\n");

    r = memcmp(s1,s2,strlen(s1));
    print(r);
    r = mymemcmp(s1,s2,strlen(s1));
    print(r);

    printf("finish \n");
    r = strcmp(s1,s2);
    print(r);
//    r = mystrcmp(s1,s2);
    print(r);
    r = linuxstrcmp(s1,s2);
    print(r);

    return 0;
}
