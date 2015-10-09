#include <stdio.h>
#include <ctype.h>
int main()
{
    char a[]="`1234567890-=`QWERTYUIOP[]\\ASDFGHJKLLLL;'ZXCVBNM,./";
    char c;
    int i;
    while((c=getchar()) !=EOF) {
        for(i=0; a[i]&&a[i]!=c; ++i)
            ;
        if(!a[i])
            putchar(c);
        else
            putchar(a[i-1]);
    }
    return 0;
}
