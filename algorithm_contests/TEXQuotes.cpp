#include <stdio.h>
int main()
{
    int c = ' ', i = 1;
    while((c=getchar())!=EOF) {
        if(c == '"') {
            printf("%s", (i==1?"``":"''"));
            i = -i;
        }else
            printf("%c", c);
    }
    return 0;
}
