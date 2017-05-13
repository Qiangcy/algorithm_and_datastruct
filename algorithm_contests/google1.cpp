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
    int n;
    cin>>n;
    for(int c=1; c<=n; ++c) {
        int t;
        cin>>t;
        cin.ignore();
        int max = 0;
        string real_res;
        for(int i=0; i<t; ++i) {
            string str;
            getline(cin, str);
            /* cout<<"str: "<<str<<endl; */
            vector<int> map(256, 0);
            int count = 0;
            for(int k=0; k<str.length(); ++k) {
                if(str[k]!=' ' && (str[k]>='A' && str[k]<='Z')) {
                    if(map[str[k]] == 0) {
                        count++;
                        map[str[k]]++;
                    }
                }
            }
            if(count > max) {
                max = count;
                real_res = str;
            }
            if(count == max) {
                if(str < real_res)
                    real_res = str;
            }

        }
        cout<<"Case #"<<c<<": "<<real_res<<endl;
    }
    return 0;
}
