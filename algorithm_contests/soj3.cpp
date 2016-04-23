#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    int x, y, tmp;
    while(cin>>y>>x) {
        vector< vector<int> > a(x);
        for(int i=0; i<x; ++i) {
            for(int j=0; j<y; ++j) {
                cin>>tmp;
                a[i].push_back(tmp);
            }
        }
        //        for(int i=0; i<x; ++i) {
        //            for(int j=0; j<y; ++j) {
        //                cout<<a[i][j]<<" ";
        //            }
        //            cout<<endl;
        //        }
        int cnt;
        for(int j=0; j<y; ++j) {
            cnt = 0;
            for(int i=0; i<x; ++i) {
                if(a[i][j] == 2)
                    a[i][j] = 0;
                else if(a[i][j] == 1)
                    cnt++;
            }
            //cout<<"cnt is "<<cnt<<endl;
            for(int i=x-1; i>-1; --i) {
                a[i][j] = 1;
                if(x-i > cnt)
                    a[i][j] = 0;
            }
        }

        for(int i=0; i<x; ++i) {
            for(int j=0; j<y; ++j) {
                cout<<a[i][j];
                if(j != y-1)
                    cout<<" ";
            }
            cout<<endl;
        }
    } return 0;
}
