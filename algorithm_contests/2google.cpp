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
    int Case;
    cin>>Case;
    for(int c=1; c<=Case; ++c) {
        int num;
        cin>>num;
        long double res = 0.0;
        long double init, income;
        if(num == 1) {
            cin>>init>>income;
            res = income/init -1;
        }else if(num == 2) {
            int second_income;
            cin>>init>>income>>second_income;
            init = -init;
            long double delta = income*income - 4*init*second_income;
            /* cout<<"delta is "<<delta<<endl; */
            if (delta >=0) {
                if (delta >0) {
                    res = (-income+sqrt(delta))/(2*init) -1;
                    double x2=(-income-sqrt(delta ))/(2*init) - 1;
                    if(x2 >= 0)
                        res = x2;
                    /* cout<<"res is "<<res<<" x2 : " <<x2<<endl; */
                } else {
                    res=-income/(2*init) -1;
                }
            }
            /* else */
            /*     cout<<"no solution"<<endl; */
        }
        cout<<"Case #"<<c<<": "<<res<<endl;
    }
    return 0;
}
