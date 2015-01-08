#include <iostream>
#include <stdio.h>
using namespace std;
void heap_sertion_sort(int *a, int length);
void heap_adjust(int *a, int length);
void swap( int &a, int &b );
int main()
{
    int length = 0;
    cin>>length;
    int *a = new int(length);
    cout<<"cin a"<<endl;
    for(int i=0; i<length; ++i)
        cin>>a[i];
    cout<<"heap sort start"<<endl;
    heap_sertion_sort(a, length);
}

void heap_sertion_sort(int *a, int length)
{
}

void heap_adjust(int *a, int length)
{
    int temp = 0;
    for(int i=(length-1)/2; i>0; i--) {
        temp = a[i];
        for(int j=(i+1)*2-1; j<length-1; j=i*2+1) {
            if(a[2*j+1] > a[j]) {
                swap(a[2*j+1], a[j]);
                //a[j] = a[2*j+1];
                //a[2*j+1] = temp;
            }
            if(a[2*j+2] > a[j]) {
                swap(a[2*j+2], a[j]);
                //a[j] = a[2*j+2];
                //a[2*j+2] = temp;
            }
        }
    }
}

void swap( int &a, int &b )
{
	int temp=b;
	b=a;
	a=temp;
}
