#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }

void permutation(vector<int> a, int cur, int n)
{
    if(cur == n) {
        for(int i=0; i<n; ++i)
            cout<<a[i]<<" ";
        cout<<endl;
    }else {
        for(int i=1; i<=n; ++i) {
            int ok = 1;
            for(int j=0; j<cur; ++j) {
                if(i == a[j]) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                a[cur] = i;
                permutation(a, cur+1, n);
            }
        }

    }
}

int main(void)
{
    vector<int> a(4, 0);
    permutation(a, 0, 4);
    return 0;
}
