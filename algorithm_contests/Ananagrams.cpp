#include <iostream>
#include <sstream>
#include <cctype>
#include <locale>
#include <set>
#include <map>
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
    string str;
    map <string, int> my_map;
    vector<string> words, res;
    while(cin>>str && str!="#") {
        words.push_back(str);
        //将toupper转换为一个返回值为int，参数只有一个int的函数指针
        transform(str.begin(), str.end(), str.begin(),  (int (*)(int))tolower);
        sort(str.begin(), str.end());
//        cout<<str<<endl;
        if(!my_map.count(str))
            my_map[str] = 0;
        else
            my_map[str]++;
    }
    for(vector<string>::iterator it=words.begin(); it!=words.end(); ++it) {
        string str = *it;
        transform(str.begin(), str.end(), str.begin(),  (int (*)(int))tolower);
        sort(str.begin(), str.end());
        if(!my_map[str]) {
            res.push_back(*it);
        }
    }
    sort(res.begin(), res.end());
    for(vector<string>::iterator it=res.begin(); it!=res.end(); ++it)
            cout<<*it<<endl;

    return 0;
}
