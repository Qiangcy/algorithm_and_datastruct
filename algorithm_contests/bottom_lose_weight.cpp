#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }

int num = 0, maxcalori=0, maxhappiness=0;
vector<int> solution(100008, 0);
vector<int> calori(108, 0);
vector<int> happiness(108, 0);

void complete(int v, int w, int m)
{
    for(int i=w; i<=m; ++i)
        solution[i] = max( solution[i], solution[i-w]+v );
}

int eat_food(vector<int>&calori, vector<int>&happiness, int left_calori, int num)
{
    vector<int> solution(left_calori, 0);
    int max_res;
    for(int j=0; j<num; ++j) {
        for(int i=calori[j]; i<=left_calori; ++i) {
            //cout<<"values ["<<j<<"] "<<happiness[j]<<"+ solution "<<i-calori[j]<<endl;
            solution[i] = max( solution[i], happiness[j]+solution[i-calori[j]] );//i-calori[j]
            //cout<<"solution["<<i<<"] "<<solution[i]<<endl;
        }
        //cout<<"solution of "<<j+1<<" is "<<max_res<<endl<<endl;
    }
    //    for(int i=0; i<left_calori; ++i)
    //        cout<<"solution ["<<i<<"] "<<solution[i]<<endl;
    //    cout<<"left is "<<left_calori<<endl;
    return solution[left_calori];
}

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input2.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif

    while(cin>> num) {
        for(int i=1; i<=num; ++i)
            cin>>calori[i]>>happiness[i];
        cin>>maxcalori;
        for(int i=1; i<=num; ++i)
            complete(calori[i], happiness[i], maxcalori);
        cout<<solution[maxcalori]<<endl;
        //        int res = eat_food(calori, happiness, maxcalori, num);
        //        cout<<res<<endl;
    }

    return 0;
}
