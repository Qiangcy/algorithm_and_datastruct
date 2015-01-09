#include <iostream>
#include <stdio.h>
using namespace std;
void heap_sertion_sort(int *a, int length);
void heap_adjust(int *a, int i, int length);
void swap( int &a, int &b );
void output(int *a, int length);
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

void output(int *a, int length)
{
    for(int i=0; i<length; ++i)
        cout<<a[i]<<' ';
    cout<<endl;
}

void heap_sertion_sort(int *a, int length)
{
    for(int i=(length-1)/2-1; i>-1; i--) {
        cout<<"heap_adjust : i"<<i<<endl;
        output(a, length);
        heap_adjust(a, i, length);
    }
}

void heap_adjust(int *a, int i, int length)
{
    int temp = 0;
    temp = a[i];
    for(int j=(i+1)*2-1; j<length-1; j=j*2+1) {
        if(a[j] > a[i]) {
            swap(a[j], a[i]);
            //a[j] = a[2*j+1];
            //a[2*j+1] = temp;
        }
        if(a[j+1] > a[i]) {
            swap(a[j+1], a[i]);
            //a[j] = a[2*j+2];
            //a[2*j+2] = temp;
        }
        cout<<"i"<<i<<"  j : "<<j<<endl;
        //cout<<"loop"<<endl;
        //char c;
        //cin>>c;
    }
    cout<<"end"<<endl;
}

void swap( int &a, int &b )
{
    int temp=b;
    b=a;
    a=temp;
}
