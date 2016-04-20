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
vector<double> BatchQueryExecutionTime
(const vector<string>&sqls, const vector<double>&times, const vector<string>&keywords) {
    vector<double> res;
    if(!sqls.size() || !times.size() || !keywords.size())
        return res;


    vector< map<string, double> > mymaps(sqls.size());
    int i = 0;
    for(auto &it : sqls) {
        string x = it;
        stringstream ss(x);
        while(ss>>x){
//            x.erase(find(begin(x), end(x), '"'));
            mymaps[i][x] = times[i];
        }
        ++i;
    }

    for(auto &it : keywords) {
        double sum = 0;
        int cnt = 0;
        for(auto &my_it : mymaps) {
            if(my_it[it]) {
                sum += my_it[it];
                cnt++;
            }
        }
        if(cnt)
            res.push_back(sum/cnt);
        else
            res.push_back(0);
    }
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
    vector<string> sqls;
    sqls.push_back("  insert into tableA values (1, \"columnA\", \"columnB\")");
    sqls.push_back("  insert into tableB values (2, \"columnA\", \"columnB\", \"columnC\")");
    sqls.push_back("select columnA, columnC from tableB");
    vector<double> times, res;
    times.push_back(2.5);
    times.push_back(12.5);
    times.push_back(30);
    vector<string> keywords;
    keywords.push_back("tableB");
    keywords.push_back("insert");
    keywords.push_back("select");
    keywords.push_back("0");
    keywords.push_back("table");
    keywords.push_back("tableA");

    res = BatchQueryExecutionTime(sqls, times, keywords);
    for(auto &it : res)
        cout<<it<<endl;

    return 0;
}
