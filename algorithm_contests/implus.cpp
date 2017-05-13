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

/*
 * Complete the function below.
 */
int maxDifference(vector < int > a) {
    if(a.size()==1)
        return -1;
    int small=a[0], greater=a[1];
    int res = greater-small;
    for(int i=1; i<a.size(); ++i) {
        if(a[i] < small) {
            small = a[i];
        }
        greater = a[i];
        if(greater-small > res)
            res = greater-small;
    }
    if(res < 0)
        res = -1;
    return res;
}

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    int _a_size = 0;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _a.push_back(_a_item);
    }

    int res = maxDifference(_a);
    fout << res << endl;

    fout.close();
    return 0;
    return 0;
}
