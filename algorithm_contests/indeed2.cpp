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
    int a, b, k;
    cin>>a>>b>>k;
    double res_a = a;
    double res_b = b+0.5;
    int cnt = 1;
    while(1) {
        if(cnt == k) {
            if(res_a < res_b)
                cout<<"Takahashi"<<endl;
            else
                cout<<"Aoki"<<endl;
            return 0;
        }
        if(res_a < res_b)
            res_a += a;
        else
            res_b += b;
        ++cnt;
    }
    return 0;
}
