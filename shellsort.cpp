#include "stdio.h"
#include "stdlib.h"
#include "header1.h"
void main()
{
    int i,a[12] = {-111,43,5,47,1,19,43,11,59,15,48,41};            /*��ʼ�����У�a[0]����������*/
    printf("The orginal data array is\n\n") ;
    for(i=1;i<=11;i++)                            /*��ʾԭ����֮�е�Ԫ��*/
        printf("%d ",a[i]);
	    printf("\n\nThe result of Shell's sorting for the array is");
    shellsort(a,11);                                /*ִ��ϣ������*/
    getchar();
	system("pause");
}


