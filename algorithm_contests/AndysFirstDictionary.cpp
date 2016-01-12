#include <iostream>
#include <set>
#include <sstream>
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
    freopen ("input2.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    string x;
    set<string> dict;
    while(cin>>x) {
        for(int i=0; i<x.length(); ++i) {
            if(!isalpha(x[i]))
                x[i] = ' ';
            else
                x[i] = tolower(x[i]);
        }
        stringstream ss(x);
        while(ss>>x)
            dict.insert(x);
    }
    //sort(dict.begin(), dict.end());
    set<string>::iterator it = dict.begin();
    for(; it!=dict.end(); ++it) {
        cout<<*it<<endl;
    }

    return 0;
}
