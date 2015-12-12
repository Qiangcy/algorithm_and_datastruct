#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }

int main(void)
{
    int n, ele, casenum=0;
//    freopen ("input.txt", "r", stdin);
    while(cin>>n>>ele && (n||ele)) {
        vector<int> vec;
        int tmp;
        for(int i=0; i<n; ++i) {
            cin>>tmp;
            vec.push_back(tmp);
        }
        sort(vec.begin(), vec.end());
        cout<<"CASE# "<<++casenum<<":"<<endl;

        vector<int>::iterator low,up;
        for(int i=0; i<ele; ++i) {
            cin>>tmp;
            low = lower_bound(vec.begin(), vec.end(), tmp);
            if(*low == tmp)
                cout<<tmp<<" found at "<<(low-vec.begin()+1)<<endl;
            else
                cout<<tmp<<" not found"<<endl;
        }
    }
    return 0;
}
