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

struct my_compare{
    bool operator() (const string& str1, const string& str2) const{
        if(str1.length()!=str2.length())
            return (str1.length()<str2.length());
        else
            return (str1.compare(str2)<=0);
    }
};

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    string str;
    while(cin>>str && !cin.eof()) {
        map<string, int, my_compare> mymap;
        int flag = 1, empty = 0;
        do {
            //cout<<str<<endl;
            string::size_type a,b;
            a = str.find(",");
            string val = str.substr(1, a-1);
            //cout << val << ' ';
            b = str.find(")");
            string direction = str.substr(a+1, b-a-1);
            //cout << direction << '\n';
            mymap[direction] = stoi(val);
            //mymap.insert(make_pair(direction, stoi(val)));
        }while(cin>>str && str.size()>2);

        vector<string> tmp;
        for(auto it : mymap) {
            tmp.push_back(it.first);
 //           cout<<" "<<it.first<<" ";
 //           cout<<" "<<it.second<<" ";
//            cout<<"count : "<<count (begin(tmp), end(tmp), it.first)<<endl;
            if(count (begin(tmp), end(tmp), it.first) > 1) {
                cout<<"not complete"<<endl;
                flag = 0;
                break;
            }
        }
        empty = count (begin(tmp), end(tmp), "");
        if(empty > 1 || !empty) {
            cout<<"not complete"<<endl;
            flag = 0;
            continue;
        }

        for(auto it= end(tmp)-1; it!=begin(tmp); --it) {
//            cout<<"tmp is "<<*it<<endl;
            string val = it->substr(0, it->size()-1);
//            cout<<"val is "<<val<<endl;
            auto result1 = find(begin(tmp), end(tmp), val);
            if (result1 == end(tmp)) {
                cout<<"not complete"<<endl;
                flag = 0;
                continue;
            }

        }

        if(flag) {
            for(map<string,int>::iterator it= begin(mymap); it!=end(mymap);) {
                cout<<it->second;
                ++it;
                if(it != mymap.end())
                    cout<<" ";
            }
//            for(auto it : mymap) {
//                cout<<it.second;
//                if(it != end(mymap)-1)
//                    cout<<" ";
//            }
            cout<<endl;
        }
        //cout<<"new "<<endl<<endl;
    }

    return 0;
}
