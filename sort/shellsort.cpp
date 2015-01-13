#include<iostream>
using namespace std;
void shellsort(int a[],int length);
int main()//—°‘Ò≈≈–Ú
{
	int a[]= {0, 9,24, 13, 87, 90, 6, 74, 100, 39, 31,33,442,321,33};//
	int length=sizeof(a)/4;
	int temp;
	for (int i=0; i<length; i++ )
        cout<<a[i]<<" ";
    cout<<endl<<"after sort"<<endl;
    shellsort(a, length);
	for (int i=0; i<length; i++ )
        cout<<a[i]<<" ";
    cout<<endl;

}

void shellsort(int a[],int length)
{
    int increment, key;
    increment = length;
    while(increment > 1) {
        increment = increment/3 + 1;
        cout<<"increment is :"<<increment<<endl;
        char z;
        cin>>z;
        for(int i=0; i<length; i+=increment) {
            key = a[i];
            cout<<"key is "<<key<<endl;
            int j =i-increment;
            while(j>=0 && key<a[j]) {
                cout<<"a["<<j<<"]  "<<a[j]<<endl;
                a[j+increment] = a[j];
                j-=increment;
            }
            cout<<"j: "<<j+increment<<"  a["<<j+increment<<"]  "<<a[j]<<"= "<<key<<endl;
            a[j+increment] = key;
        }

        for (int i=0; i<length; i++ )
            cout<<a[i]<<" ";
        cout<<endl<<"next"<<endl<<endl;
    }
}
