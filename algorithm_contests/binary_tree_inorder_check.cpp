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

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    int CASE;
    cin>>CASE;
    ///cout<<"case "<<CASE<<endl;
    while(CASE--) {
        string s;
        cin>>s;
        if(s=="")
            continue;
        int old_pos = 0, new_pos = 0;
        int i = 0, flag=1;
        for(auto it=begin(s); it!=end(s); ++it) {
            //cout<<*it<<" ";
            if(*it == '#' && *(it+1)=='#') {
                cout<<"no"<<endl;
                flag = 0;
                break;
            }

            if(*it == '#') {
                old_pos = new_pos;
                new_pos = i;
                if(new_pos!=1 && old_pos != 0 && new_pos-old_pos == 1) {
                    cout<<"no"<<endl;
                    flag = 0;
                    break;
                }
            }
            i++;
        }
        if(flag)
            cout<<"yes"<<endl;
        //cout<<"end"<<endl<<endl;
    }

    return 0;
}
