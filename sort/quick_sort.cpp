#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define RANNUM 15

int partition(int *a, int left, int right);
void swap( int &a, int &b );
void quick_sort(int *a, int left, int right);
int main()
{
    timeval starttime, endtime;
    int i;
    int a[RANNUM];
    for(int i=0; i<RANNUM; ++i) {
        a[i] = rand() % RANNUM;
    }
    int length = sizeof(a)/sizeof(int);
    for(i=0; i<length; ++i)
        printf("%d ", a[i]);
    printf("length: %d ", length);
    printf("\nsecond\n");
    gettimeofday(&starttime, 0);
    time_t first = clock();
    quick_sort(a, 0, length-1);
    time_t second = clock();
    printf("First Clock end :%lf ", second-first);
    gettimeofday(&endtime, 0);
    double timeuse = endtime.tv_usec-starttime.tv_usec;//1000000*(endtime.tv_sec - starttime.tv_sec)+
    timeuse /= 1000;
    printf("Clock end:%lf ", timeuse);
    printf("\nend\n");
    for(i=0; i<length; ++i)
        printf("%d ", a[i]);
}

int partition(int *a, int left, int right)
{
    int m = left + (right-left)/2;
    printf("left is %d, m is %d, right is %d \n",left, m, right);
    for(int i=0; i<right; ++i)
        printf("%d ", a[i]);
    if(a[left] > a[right])
    {
        swap(a[left], a[right]);
        printf("first swap(%d, %d)\n", a[left], a[right]);
    }
    if(a[m] > a[right])
    {
        swap(a[m], a[right]);
        printf("second swap(%d, %d)\n", a[m], a[right]);
    }
    if(a[m] < a[left])
    {
        swap(a[m], a[left]);
        printf("third swap(%d, %d)\n", a[m], a[left]);
    }
    int pivot_key = a[left];
    printf("pivot key is %d \n", pivot_key);
    //cout<<"pivot key is "<<pivot_key<<endl;
    while(left < right) {
        while(left<right && a[right]>=pivot_key)
            --right;
       a[left] = a[right];
//        printf("\n left: %d, right: %d ", left, right);
//        swap(a[left], a[right]);
        while(left<right && a[left]<=pivot_key)
            ++left;
        a[right] = a[left];
//        swap(a[left], a[right]);
    }
    a[left] = pivot_key;
    return left;
}

void quick_sort(int *a, int left, int right)
{
//   printf("\ninb\n");
  // for(int i=0; i<right; ++i)
  //      printf("%d ", a[i]);
    int pivot;
    if(left < right) {
        pivot = partition(a, left, right);
 //       printf("\n pivot: %d ", pivot);
        quick_sort(a, pivot+1, right);
        quick_sort(a, left, pivot-1);
    }
}

void swap( int &a, int &b )
{
//    printf("in3");
    int temp=b;
    b=a;
    a=temp;
}
