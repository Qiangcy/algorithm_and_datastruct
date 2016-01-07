#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }
int tot=0;
int n_queen = 26;

void search(vector<int> a, int cur)
{
    if(cur == n_queen) {
        tot++;
        return;
    }else {
        for(int i=0; i<n_queen; ++i) {
            int ok = 1;
            a[cur] = i;
            for(int j=0; j<cur; ++j) {
                if(a[cur]==a[j] || cur-a[cur]==j-a[j] || cur+a[cur]==j+a[j]) {
                    ok = 0;
                    break;
                }
            }
            if(ok)
                search(a, cur+1);
        }
    }
}

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    vector<int> a(n_queen, -1);
    search(a, 0);
    cout<<"tot is "<<tot<<endl;
    return 0;
}
