#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

void myprintf(const char *format, ...)
{
    va_list ap;
    char c;
    va_start(ap, format);
    while ((int)(c = *format++)) {
        switch(c) {
            case 'c': {
                          /* char is promoted to int when passed through '...' */
                          char ch = va_arg(ap, int);
                          putchar(ch);
                          break;
                      }
            case 'd':case 'x': case 'o': {
                                             int base = 10;
                                             if(c == 'x')
                                                 base = 16;
                                             else if(c == 'o')
                                                 base = 8;
                                             int i = 0, sign = 1, d = va_arg(ap, int);
                                             char *ret = (char*)malloc(12);//10nums,1sign, and 1 for '\0'
                                             memset(ret, 12, 0);

                                             const char *digits = "0123456789abcdefx";
                                             if(d < 0) {
                                                 if(d == -4294967296) {//for maxminus
                                                     d += 1;
                                                     sign = -1;
                                                 } else
                                                     sign = 0;
                                                 d = -d;
                                             }

                                             do {
                                                 ret[i++] = digits[d%base];
                                                 d /= base;
                                             } while(d > 0);

                                             int j = 0;
                                             char temp;
                                             for(i -= 1; j<i; ++j, --i) {
                                                 temp = ret[j];
                                                 ret[j] = ret[i];
                                                 ret[i] = temp;
                                             }
                                             if(sign != 1) {
                                                 memmove(ret+1, ret, strlen(ret));
                                                 ret[0] = '-';
                                                 if(sign == -1)
                                                     ret[11] = 6;
                                             }
                                             fputs(ret, stdout);
                                             break;
                                         }
            case 's': {
                          char *p = va_arg(ap, char *);
                          fputs(p, stdout);
                          break;
                      }
            default:
                      putchar(c);
        }
    }
    va_end(ap);
}

int main(void)
{
    myprintf("c\ts\td\to\tx\n", '1', "hello", 42949672, 15, 15);
    return 0;
}
