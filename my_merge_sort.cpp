#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int swap[], int n);
void merage_sort(int a[], int swap[], int k, int n);

int main()
{
    int a[] = {1, 12, 31, 21, 41, 14, 31, 22, 45, 32};
    int length = sizeof(a)/4;
    int *swap = (int*)malloc(length);
    for (int i=0; i<length; ++i)
        printf("%d  ", a[i]);
    printf("*******************************\n\n");
    sort(a, swap, length);
    for (int i=0; i<length; ++i)
        printf(" %d  ", swap[i]);
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
		printf("\nfl is  %d,  fr is  %d,  sl is  %d, sr is  %d\n\n", fl, fr, sl, sr);
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

		for (int i=0; i<n; ++i)
			printf(" %d  ", swap[i]);
		fl = sr + 1;
	}
	for(; fl<n; ++fl) {
		swap[m] = a[fl];
		++fl;
		++m;
	}
	for(int i=0; i<n; ++i) {
		a[i] = swap[i];
	}
	printf("\n\n******************************************\n\n");
}
