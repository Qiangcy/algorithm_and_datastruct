#include <stdio.h>
#include <stdlib.h>
#define N 40
int a[N];

int GCD(int a, int b)
{
    if(a%b == 0)
        return b;
    else
        return GCD(b, a%b);
}

int w_GCD(int a, int b)
{
    while(a%b != 0) {
        int temp = a;
        a = b;
        b = temp%b;
    }
    return b;
}


int Fibonacci(int n)
{
    if(n==0 || n==1)
        return 1;
    else
        return Fibonacci(n-1) + Fibonacci(n-2);
}
int w_Fibonacci(int n)
{
    int i, sum=1, before=1;
    for(i=1; i<n; ++i) {
        sum += before;
        before = sum;
    }
    return sum;
}

int count(void)
{
    int i, count=1;
    for(i=10; i<=100; ++i) {
        if(i/9==0 || i%10 == 9) {
            ++count;
        }
    }
    return count;
}

int factorial(int n)
{
    n += 1;
    int result = 1;
    int i = 1;
    do {
        result = result * i;
        i = i + 1;
    } while (i < n);
    return result;
}

void print_numbers(void)
{
    int i, j;
    for(i=1; i<10; ++i) {
        for(j=1; j<=i; ++j) {
            printf("%d\t", i*j);
        }
        printf("\n");
    }
}

void diamod(int num, char graph)
{
    if(num%2 == 0) {//num & 1
        printf("wrong\n");
        return;
    }
    int half, i;
    half = num/2;
    for(i=0; i<=half; ++i) {
    }

}

void gen_random(int upper_bound)
{
    int i;
    for (i = 0; i < N; i++)
        a[i] = rand() % upper_bound;
}
int main(void)
{
    int i, histogram[10] = {};
    gen_random(10);
    for (i = 0; i < N; i++)
        ++histogram[a[i]];

    int j, sum;
    for(i=0; i<=9; i++)
        printf("%d ", i);
    printf("\n");
    for(i=0; i<=9; i++)
        printf("%d ", histogram[i]);
    printf("\n");
    do {
        sum = 0;
        for(i=0; i<=9; i++)
            sum += histogram[i];
        for(j=0; j<=9; ++j) {
            if(histogram[j]!=0) {
                printf("* ");
                --histogram[j];
            }else
                printf("  ");
        }
        printf("\n");
    } while(sum != 0);
    return 0;
}

//int main(void)
//{
//    int a, b, c;
//    scanf("%d, %d", &a, &b);
//    printf("GCD result is %d\n", GCD(a, b));
//    printf("W_GCD result is %d\n", GCD(a, b));
//    scanf("%d", &c);
//    printf("Fibonacci result is %d\n", Fibonacci(c));
//    printf("w_Fibonacci result is %d\n", w_Fibonacci(c));
//    printf("\n\n Count %d\n", count());
//    printf("\n\n factorial %d\n", factorial(10));
//    printf("\n\n printf_number \n");
//    print_numbers();
//}
