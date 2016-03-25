#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct _base {
    int a;
    double b;
    double c;
    void (*base_constructor_fun)(void*);
    void (*print_base_fun)(void*);
    double (*base_add_fun)(void*, double);
}base;

typedef struct _base_father {
    char d;
    float e;
}base_father;

void print_base(void* mythis)
{
    printf("a is %d \n", ((base*)mythis)->a);
    printf("b is %f \n", ((base*)mythis)->b);
    printf("c is %f \n", ((base*)mythis)->c);
}

void base_constructor(void* mythis)
{
    ((base*)mythis)->a = 1;
    ((base*)mythis)->b = 2.2;
    ((base*)mythis)->c = 3.3;
    ((base*)mythis)->base_constructor_fun = &base_constructor;
    ((base*)mythis)->print_base_fun = &print_base;
}


double base_add(void* mythis, double c)
{
    double res = ((base*)mythis)->a + ((base*)mythis)->b + c;
    return res;
}

int main(void)
{
    printf("begin \n");
    base* mybase = (base*)malloc(sizeof(base));
    base_constructor(mybase);
    mybase->print_base_fun(mybase);
    double res = mybase->base_add_fun(mybase, 1000.2222);
    printf("res is %lf \n", res);
    return 0;
}
