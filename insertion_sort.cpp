#include <stdio.h>
void insertion_sort(int *a, int length);
int main()
{
    int a[] = {3, 7, 5, 0, 12, 1, 3, 1,4};
//    printf("%d ", sizeof(a));
    insertion_sort(a, sizeof(a)/sizeof(int));
        printf("\n\n ");
    for(int i=0; i<sizeof(a)/sizeof(int); ++i) {
        printf("%d ", a[i]);
    }
}
void insertion_sort(int *a, int length)
{
    int i = 1, j = 0, key = 0;
    for(; i<length; ++i) {
        key = a[i];
        j = i - 1;
        while(j>=0 && key<a[j]) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
    }
    for(i=0; i<length; ++i) {
        printf("%d ", a[i]);
    }
}
