#include <iostream>
using namespace std;
void swap( int &a, int &b );
int main()//ð���㷨���ر𣩣����ǰ�٣�������
{
	int a[] = { 4,2,5,3,7,2,8,3,1,33,23,444,223,12,32,452,2,1,44,2,222,32,31,33,442,321,33 };
	int length = sizeof(a)/sizeof(int) ;
	for ( int i=0; i<length; i++ )
	{
		for ( int j=i; j>0; j-- )
		{
			if( a[j]<a[j-1] )
				swap( a[j], a[j-1] );
			else//�Ż�, �����Ѿ�������������ж�;
				break;
		}
	}
	for ( int i=0; i<length; i++ )
		cout<<a[i]<<" ";
	system("pause");
}
void swap( int &a, int &b )
{
	int temp=b;
	b=a;
	a=temp;
}