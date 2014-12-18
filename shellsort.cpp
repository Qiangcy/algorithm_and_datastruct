#include "stdio.h"
#include "stdlib.h"
#include "header1.h"
void main()
{
    int i,a[12] = {-111,43,5,47,1,19,43,11,59,15,48,41};            /*初始化序列，a[0]可任意置数*/
    printf("The orginal data array is\n\n") ;
    for(i=1;i<=11;i++)                            /*显示原序列之中的元素*/
        printf("%d ",a[i]);
	    printf("\n\nThe result of Shell's sorting for the array is");
    shellsort(a,11);                                /*执行希尔排序*/
    getchar();
	system("pause");
}


