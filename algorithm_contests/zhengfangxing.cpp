

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool low(int i, int j) { return i<j; }
bool big(int i, int j) { return i>j; }
int main()
{
    int n=0;
    int x=-1, y=-1;
    int c=0, d=0;
    cin>>x>>y;
    while(!(x==0 && y==0)) {
        vector<int> chang;
        vector<int>  kuan;
        chang.push_back(x);
        kuan.push_back(y);
        cin>>c>>d;
        while(!(c==0 && d==0)) {
            chang.push_back(c);
            kuan.push_back(d);
            cin>>c>>d;
        }
        cout<<*std::min_element(chang.begin(), chang.end(), low)<<" ";
        cout<<*std::min_element(kuan.begin(), kuan.end(), low)<<" ";
        cout<<*std::max_element(chang.begin(), chang.end(), low)<<" ";
        cout<<*std::max_element(kuan.begin(), kuan.end(), low)<<endl;
        chang.clear();
        kuan.clear();
        //cout<<"endl"<<endl;
        cin>>x>>y;

    }
}
