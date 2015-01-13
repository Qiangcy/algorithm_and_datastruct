#include <iostream>
#include <stdio.h>
using namespace std;
void heap_sertion_sort(int *a, int length);
void heap_adjust(int *a, int i, int length);
void heap_sort(int *a, int length);
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
    heap_sort(a, length-1);
    cout<<"heap sort end"<<endl;
    output(a, length);
}

void output(int *a, int length)
{
    for(int i=0; i<length; ++i)
        cout<<a[i]<<' ';
    cout<<endl;
}

void heap_sertion_sort(int *a, int length)
{
    for(int i=length/2-1; i>-1; i--) {
        cout<<"heap_adjust : i"<<i<<endl;
        output(a, length);
        heap_adjust(a, i, length);
    }
}

void heap_adjust(int *a, int i, int length)
{
    int temp = 0;
    temp = a[i];
    for(int j=i*2+1; j<length; j=j*2+1) {
        cout<<"i"<<i<<"  j : "<<j<<endl;
        if(j<length-2 && a[j] < a[j+1])
            ++j;
        if(temp > a[j])
            break;
        a[i] = a[j];
        i = j;
    }
    a[i] = temp;
}

void heap_sort(int *a, int length)
{
    for(int i=length; i>0; --i) {
        heap_sertion_sort(a, i);
        swap(a[0], a[i]);
    }
}
