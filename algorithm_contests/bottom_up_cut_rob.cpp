#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }

int cut_rop(vector<int>&values, int left, int num)
{
    vector<int> solution(left+1, 0);
    int max_res;
    for(int j=0; j<left; ++j) {
        max_res = -100;
        for(int i=0; i<=j; ++i) {
            cout<<"values ["<<i<<"] "<<values[i]<<"+ solution "<<j-i<<endl;
            max_res = max(max_res, values[i]+solution[j-i]);
            cout<<"max_res is "<<max_res<<endl;
        }
        solution[j+1] = max_res;
        cout<<"solution of "<<j+1<<" is "<<max_res<<endl<<endl;
    }
    cout<<"left is "<<left<<endl;
    return solution[left];
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
