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
    string s1, s2;
    cin>>s1>>s2;
    unordered_map<char, int> hash;
    if(s1.length() > s2.length()) {
        for(int i=0; i<s1.length(); ++i)
            hash[s1[i]] = 1;
        for(int i=0; i<s2.length(); ++i)
            if(hash.find(s2[i])==end(hash)) {
                cout<<"Impossible"<<endl;
                return 0;
            }
    }else {
        for(int i=0; i<s2.length(); ++i)
            hash[s2[i]] = 1;
        for(int i=0; i<s1.length(); ++i)
            if(hash.find(s1[i])==end(hash)) {
                cout<<"Impossible"<<endl;
                return 0;
            }
    }
    cout<<"Possible"<<endl;
    return 0;

}


