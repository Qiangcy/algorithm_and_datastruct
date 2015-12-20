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
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    int  xie=0,res=0;
    while(cin>>xie) {
        //cout<<"xie "<<xie<<endl;
        res = 0;
        for(int i=1; i<=xie; ++i){
            for(int j=1; j<=xie; ++j){
         //       cout<<pow(x,2)<<" + "<<pow(y, 2)<<" = "<<pow(x,2)+pow(y,2)<<endl;
                if(pow(i,2)+pow(j,2) == pow(xie, 2)) {
                    //cout<<"i is "<<i<<" j is "<<j<<endl;
                    ++res;
                }
            }
        }
        cout<<res/2<<endl;
    }
    return 0;
}
