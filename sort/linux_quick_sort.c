#include <stdio.h>
/* Sdumk 是但 */

void swap( int *a, int *b )
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

int order_partition(int a[], int start, int end, int k)
{
    int pivot = a[end];
    int i;
    while(start < end) {
        while(start<end && a[start]<=pivot)
            ++start;
        a[end] = a[start];
        while(start<end && a[end]>=pivot)
            --end;
        a[start] = a[end];
    }
    a[start] = pivot;
    return start;
}

int order_statistic(int a[], int start, int end, int k)
{
    int i;
    if(end >= start) {
        i = order_partition(a, start, end, k);
        if(k == i)
            return a[i];
        else if(k > i)
            return order_statistic(a, i+1, end, k);
        else
            return order_statistic(a, start, i-1, k);
    }
}

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int i;
    while(start < end) {
        while(start<end && a[start]<=pivot)
            ++start;
        a[end] = a[start];
        while(start<end && a[end]>=pivot)
            --end;
        a[start] = a[end];
    }
    a[start] = pivot;
    return start;
}

void quicksort(int a[], int start, int end)
{
    int mid;
    if(end > start) {
        mid = partition(a, start, end);
        quicksort(a, start, mid-1);
        quicksort(a, mid+1, end);
    }
}

int main(void)
{
    int a[] = {7, 6, 9, 5, 4};
    int i = -1;
    i = order_statistic(a, 0, 4, 0);
    printf("final i is %d\n", i);
    for(i=0; i<5; ++i)
        printf("%d ", a[i]);
    printf("\n");
}
