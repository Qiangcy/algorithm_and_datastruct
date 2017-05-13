#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }

void print(vector<int> a){
    for(auto &it : a) {
        cout<<it<<" ";
    }
    cout<<endl;
}

int partition(vector<int> a, int m, int n)
{
    int key = a[m], idx=m;
    int i=0;
    while(1) {
        cout<<" m is "<<m<<" n is "<<n<<endl;
        print(a);
        cout<<endl;
        char c; scanf("%c", &c);
        if(m == n)
            return m;
        while(a[m] < key) {
            m++;
        }
        swap(a[idx], a[m]);
        idx = m;

        while(a[n] > key) {
            n--;
        }
        swap(a[idx], a[n]);
        idx = n;
    }
}

void quicksort(vector<int> a, int m, int n)
{
    if(m == n)
        return;
    int partition_idx = partition(a, m, n);
    quicksort(a, m, partition_idx);
    return;

//    quicksort(a, partition_idx, n);
}

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    vector<int> nums;
    int n, tmp;
    cin>>n;
    for(auto i=0; i<n; ++i) {
         cin>>tmp;
         nums.push_back(tmp);
    }


    quicksort(nums, 0, nums.size()-1);
    return 0;
}
