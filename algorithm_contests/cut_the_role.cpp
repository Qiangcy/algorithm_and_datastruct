#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

int cut_rop(vector<int>&values, int left, int num)
{
    int max_res = -100;
    if(left == 0) {
        cout<<" return 0"<<endl;
        return 0;
    }
    cout<<"left "<<left<<endl;
    for(int i=0; i<num; ++i) {
        if(left-i-1 < 0) {
            cout<< "continue"<<endl;
            break;
        }else {
            cout<<"values ["<<i<<"] "<<values[i]<<endl;
            max_res = max(max_res, values[i]+cut_rop(values, left-i-1, num));
            cout<<"max_res is "<<max_res<<endl;
        }
    }
    return max_res;
}

int main(void)
{
    freopen ("input.txt", "r", stdin);
    int length, num, tmp;
    cin>>length>>num;
    vector<int> values;
    for(int i=0; i<num; ++i) {
        cin>>tmp;
        values.push_back(tmp);
    }
    int res = cut_rop(values, length, num);
    cout<<"res is "<<res<<endl;
    return 0;
}
