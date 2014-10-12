#include<iostream>
using namespace std;
void swap( int &a, int &b );
int main()//选择排序
{
	int a[]={4,2,1,3,5,5,3,2,8,9,1,33,23,444,223,12,32,452,2,1,44,2,222,32,31,33,442,321,33};//
	int length=sizeof(a)/4;
	int temp;
	for ( int i=0; i<length; i++ )
	{
		int min = a[i];//第i个默认为min,找到比他少的就交换
		for ( int j=i; j<length; j++ )
		{
			if( a[j]<=min )
			{
				 min=a[j];//swap( min,a[j] );不符合选择排序，直接就交换了，降低效率 
				 temp=j;
			}
		}
		swap( a[temp], a[i] );
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