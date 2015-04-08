#include <stdio.h>
#include <math.h>

int binary_search_iter(int a[], int low, int high, int element)
{
    if(low>high)
        return -2;
    int mid = (low+high)/2;
    if(element == a[mid])
        return mid;
    else if(element < a[mid])
        return binary_search_iter(a, 0, mid-1, element);
    else
        return binary_search_iter(a, mid+1, high, element);
}

int binary_search(int a[], int low, int high, int element)
{
    int mid = -2;
    while(low <= high) {
        mid = (low+high)/2;
        if(a[mid] == element) {
            while(a[mid-1] == element)/* return first element */
                --mid;
            break;
        }
        else if(element < a[mid])
            high = mid-1;
        else
            low = mid+1;
    }
//    printf("low is %d, high is %d\n", low, high);
    if(low > high)
        return -2;
    return mid;
}


double mysqrt(double y)
{
    double low=0, high=y, mid = -2;
    while(low < high) {
        mid = (low+high)/2;
        //printf("low is %lf, mid is %lf, high is %lf\n", low, mid, high);
        if(abs(pow(mid, 2)-y) < 0.00001)
            break;
        else if(pow(mid, 2) < y)
            low = mid+0.00001;
        else
            high = mid-0.00001;
    }
    return mid;
}

int main(void)
{
    //int a[] = {1, 2, 3, 5, 5, 6, 8, 9};
    int a[] = {1, 2, 2, 2, 5, 6, 8, 9};
    printf("binary_search_iter is %d\n", binary_search_iter(a, 0, 7, 2)+1);
    printf("binary_search is %d\n", binary_search(a, 0, 7, 2)+1);
    printf("mysqrt is %lf\n", mysqrt(4));
    return 0;
}
