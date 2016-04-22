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
    int n, tmp=0;

    while(cin>>n) {
        int a[7];
        memset(a, 0, sizeof(a));
        for(int i=0; i<n; ++i) {
            cin>>tmp;
            a[i%7] += tmp;
        }
        for(int i=0; i<7; ++i)
            cout<<a[i]<<endl;
    }

    return 0;
}
