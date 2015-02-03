#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
void my_sprintf(double val, int precision, char format);
using namespace std;
int main()
{
    double val = 1234.999999;
    cout<<"cin val"<<endl;
    cin>>val;
    cout<<"cin precision"<<endl;
    int precision = 0;
    cin>>precision;
    cout<<"cin format(e,f,g)"<<endl;
    char format = 'f';
    cin>>format;
    my_sprintf(val, precision, format);
}

void my_sprintf(double val, int precision, char format)
{
    int mysign = 1, exponent = 0;
    if(format == 'e' || format == 'g') {
        if(val >= 10) {
            mysign = 1;
            while(val >= 10) {
                val /= 10;
                ++exponent;
            }
        }else if(val < 1) {
            mysign = 0;
            while(val < 1) {
                val *= 10;
                ++exponent;
            }
        }

        if(format == 'g') {
            if(exponent < -4)
                format = 'e';
            else
                format = 'f';
        }
    }
    printf(" \n after e :  %f exponent is  %d  \n" , val, exponent);

    double float_val, temp, back_up = val;
    int len = 0;
    int base = 10, up_to_integer = 0;
    int i = 0, j = 0;
    char *buf = new char(100);
    const char *digits;
    digits = "0123456789ABCDEFX";

    float_val = val - (int)val;
    printf("origin is %f\n", val);
    cout<<"float_val after (int) is "<<float_val<<endl;
    for(int i=0; i<precision; ++i)
        float_val *= 10;

    printf("before round is %f \n", float_val);
    printf("after  round is %f \n", round(float_val));

    temp = float_val = round(float_val);
    printf("temp %f \n log 10 %f \n log 10 %f\n", temp, log10(temp), floor(log10(temp))+1);
    while(temp != 0) {
        temp = (int)temp / 10;
        ++i;
    }
    cout<<"i is : "<<i<<endl;
    if(i > precision) {
        printf("%f\n", val);
        val += 1;
        up_to_integer = 1;
        printf("up to integer and val is  %f\n", val);
    }
    else
        cout<<"NO up to integer"<<endl;

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
    cout<<endl<<"second buf is "<<buf<<endl;
    printf("float_val is %f\n", float_val);
    i = len;
    if(up_to_integer) {
        for(j=0; j<precision; ++j,++i)
            buf[i] = '0';
        buf[i] = '\0';
    }else {
        while(float_val != 0) {
            j = (int)float_val%base;
            float_val = (int)float_val/base;
            buf[i++] = digits[j];
            //cout<<" and j is "<<j<<' ';
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
    printf("\nvalue %f using sprintf", back_up);
    cout<<endl<<"****result is  "<<buf<<"**********"<<endl;
}
