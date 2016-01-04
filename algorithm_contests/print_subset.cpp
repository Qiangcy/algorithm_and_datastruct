#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }
vector<int> b;

void print_subset_a(vector<int> a, int cur)
{
    int n = a.size();
//    cout<<"Cur is "<<cur<<endl;
    if(cur == n) {
        for(int i=0; i<n; ++i)
            if(b[i] == 1)
                cout<<a[i]<<" ";
        cout<<endl;
        return;
    }
    b[cur] = 1;
    print_subset_a(a, cur+1);
    b[cur] = 0;
    print_subset_a(a, cur+1);
}

int main(void)
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    b = vector<int>(a.size(), 0);
    print_subset_a(a, 0);
    return 0;
}
