#include <iostream>
#include <vector>
#include <cstdio>
//#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

int go(vector<int> &a, int p, int step, int n)
{
    int tmp = 0, rec = p;
    while(tmp < abs(step)) {
        p = (p+n+ (int)(step/abs(step)) ) %n;
        if(a[p] == 0)
            continue;
        ++tmp;
    }
    return p;
}

int main(void)
{
    int n, k, m;
    while(cin>>n>>k>>m && n+k+m!=0) {
        int i=1, j=n;
        vector<int> a(n, 1);
        int left = n;
        while(left > 0) {
            j = go(a, j,  k, n);
            i = go(a, i, -m, n);
            a[i] = a[j] = 0;
            if(j == 0)
                printf("%3d", n);
            else
                printf("%3d", j);
            --left;
            if(j != i) {
                --left;
                if(i == 0)
                    printf("%3d", n);
                else
                    printf("%3d", i);
            }
            if(left > 0)
                cout<<",";
        }
        cout<<endl;
    }
    return 0;
}
