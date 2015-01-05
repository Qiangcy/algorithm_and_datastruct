#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#define RANNUM 30000

void sort(int a[], int swap[], int n);
void merage_sort(int a[], int swap[], int k, int n);

int main()
{
    timeval starttime, endtime;
    int a[RANNUM];
    int length = sizeof(a)/4;
    int *swap = (int*)malloc(length);
    for(int i=0; i<RANNUM; ++i) {
        a[i] = rand() % RANNUM;
    }
//    for (int i=0; i<length; ++i)
//        printf("%d  ", a[i]);
    printf("*******************************\n\n");
    gettimeofday(&starttime, 0);
    time_t first = clock();
    sort(a, swap, length);
    time_t second = clock();
    printf("First Clock end :%lf ", second-first);
    gettimeofday(&endtime, 0);
    double timeuse = 1000000*(endtime.tv_sec - starttime.tv_sec)+endtime.tv_usec-starttime.tv_usec;
    timeuse /= 1000;
    printf("Clock end:%lf ", timeuse);
   // for (int i=0; i<length; ++i)
   //     printf(" %d  ", swap[i]);
    return 0;
}

void sort(int a[], int swap[], int n)
{
    for(int k=1; k<n; k=k*2) {
        //		if( k==0 )
        //		{
        //			merage_sort(a, swap, 0, n);
        //			printf("finish %d\n", k);
        //			k = 1;
        //			merage_sort(a, swap, 1, n);
        //			printf("finish %d\n", k);
        //		}
        //		else
        merage_sort(a, swap, k-1, n);
        printf("finish %d\n", k);
    }
}

void merage_sort(int a[], int swap[], int k, int n)
{
    int fl = 0, m = 0;
    while(fl <= n-1) {
        int fr = fl+k;
        int sl = fr+1, sr = sl+k;
        if(sr+1 >= n)
            sr = n - 1;
		//printf("\nfl is  %d,  fr is  %d,  sl is  %d, sr is  %d\n\n", fl, fr, sl, sr);
		for(; fl<=fr && sl<=sr; ++m) {
			if(a[fl] < a[sl]) {
				swap[m] = a[fl];
				++fl;
			} else {
				swap[m] = a[sl];
				++sl;
			}
		}

		while(fl <= fr) {
			swap[m] = a[fl];
			++m;
			++fl;
		}
		while(sl <= sr) {
			swap[m] = a[sl];
			++m;
			++sl;
		}

//		for (int i=0; i<n; ++i)
//			printf(" %d  ", swap[i]);
		fl = sr + 1;
	}
	for(; fl<n; ++fl) {
		swap[m] = a[fl];
		++fl;
		++m;
	}
//	for(int i=0; i<n; ++i) {
//		a[i] = swap[i];
//	}
	printf("\n\n******************************************\n\n");
}
