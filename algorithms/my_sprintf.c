#include <stdio.h>
//#include <iostream>
#include<stdlib.h>
#include <math.h>
#include <string.h>
void my_sprintf(long double val, int precision, char format);
int main()
{
    long double val = 1234.999999;
    int precision = 0;
    char format = 'e';
    printf("cin val\n");
  //  std::cin>>val;
    scanf("%Lf", &val);
    printf("cin precision\n");
    scanf("%d", &precision);
    printf("cin format(e,f,g)\n");
   // fflush(stdout);
   // fflush(stdin);
//    scanf("%c", &format);
    my_sprintf(val, precision, format);
}

void my_sprintf(long double val, int precision, char format)
{
    int mysign = 1, exponent = 0;
    if(format == 'e' || format == 'g') {
        if(val >= 10) {
            mysign = 1;
            while(val >= 10) {
                val /= 10;
                ++exponent;
                printf("origin with e is %Lf\n", val);
            }
        }else if(val < 1) {
            mysign = 0;
            while(val < 1) {
                val *= 10;
                ++exponent;
            }
        }
//        precision -= exponent;

        if(format == 'g') {
            if(exponent < -4)
                format = 'e';
            else
                format = 'f';
        }
    }
    printf(" \n after e :  %Lf exponent is  %d  \n" , val, exponent);
    printf("sizeof(long double) is %d \n" , sizeof(long double));

    long double float_val;
    long double back_up = val;
    double temp;
    int len = 0;
    int base = 10, up_to_integer = 0;
    int i = 0, j = 0;
    char *buf = (char *)malloc(100);
    //char *buf = new char(100);
    const char *digits;
    digits = "0123456789ABCDEFX";


    printf("(int)val is  %d \n", (int)val);
    float_val = val - (long int)val;
    printf("origin is %Lf\n", val);
    int y = 0;
    for(y=0; y<precision; ++y) {
        float_val *= 10;
        printf("float_val is %Lf \t", float_val);
        int *p = (int *)&float_val;
        int j = 0;
        for(j=8*sizeof(int); j>=0; --j)
            printf("%d", ((*p)>>j)&1);
        printf("\n");
    }

//    printf("before round is %Lf \n", float_val);
//    printf("after  round is %f \n", round(float_val));
//
//  temp = float_val;// = round(float_val);
//    printf("temp %Lf \n log 10 %f \n log 10 %Lf\n", temp, log10(temp), floor(log10(temp))+1);
    while(temp != 0) {
        temp = (int)temp / 10;
        ++i;
    }
    //cout<<"i is : "<<i<<endl;
    if(i > precision) {
        printf("%Lf\n", val);
        val += 1;
        up_to_integer = 1;
        printf("up to integer and val is  %Lf\n", val);
    }
    else
        printf("NO up to integer") ;

    i = 0;
    while(val != 0) {
        j = (int)val%base;
        val = (int)val/base;
        buf[i++] = digits[j];
        //cout<<" and j is "<<j<<' ';
    }
    buf[i] = '\0';

    printf("first buf is %s", buf);
    j = 0;
    while(--i > j) {
        char tmp = buf[j];
        buf[j] = buf[i];
        buf[i] = tmp;
        j++;
    }
    len = strlen(buf);
    if(precision != 0)
        buf[len++] = '.';
    //cout<<endl<<"second buf is "<<buf<<endl;
    printf("float_val is %Lf\n", float_val);
    i = len;
    if(up_to_integer) {
        for(j=0; j<precision; ++j,++i)
            buf[i] = '0';
        buf[i] = '\0';
    }else {
        while(float_val != 0) {
            j = (long long int)float_val%base;
            float_val = (long long int)float_val/base;
            buf[i++] = digits[j];
            //cout<<" and j is "<<j<<' ';
        }
        buf[i] = '\0';

    printf("float result is %s", buf);
        j = len;
        while(--i > j) {
            char tmp = buf[j];
            buf[j] = buf[i];
            buf[i] = tmp;
            j++;
        }
    }

//    printf("final result is %s *******\n", buf);
    len = strlen(buf);
    if(format == 'e') {
        buf[len++] = 'e';

        if(mysign == 1)
            buf[len++] = '+';
        else
            buf[len++] = '-';

        if(exponent < 100)
            buf[len++] = '0';
        if(exponent < 10) {
            buf[len++] = '0';
            buf[len++] = exponent + '0';
            buf[len] = '\0';
        }else {
            printf("e >= 10");
            i = len;
            while(exponent != 0) {
                j = exponent%base;
                exponent = exponent/base;
                buf[i++] = digits[j];
            }
            buf[i] = '\0';

            j = len;
            while(--i > j) {
                char tmp = buf[j];
                buf[j] = buf[i];
                buf[i] = tmp;
                j++;
            }
        }

    }
    printf("\nvalue %Lf using sprintf", back_up);
    printf("\n*******result is %s *******\n", buf);
}
