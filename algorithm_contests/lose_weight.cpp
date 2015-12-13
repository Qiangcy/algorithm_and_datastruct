#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }

int eat_food(vector<int>&calori, vector<int>&happiness, int left_calori, int num)
{
    int max_res = -100;
    if(left_calori == 0) {
        //cout<<" return 0"<<endl;
        return 0;
    }
    //cout<<"left_calori "<<left_calori<<endl;
    for(int i=0; i<num; ++i) {
        if(left_calori-calori[i] < 0) {
            //cout<< "continue"<<endl;
            continue;
        }else {
            //cout<<"calori ["<<i<<"] "<<calori[i]<<endl;
            max_res = max(max_res,happiness[i]+eat_food(calori, happiness, left_calori-calori[i], num));
            //cout<<"max_res is "<<max_res<<endl;
        }
    }
    return max_res;
}



int main(void)
{
    freopen ("input2.txt", "r", stdin);
    int num = 0, maxcalori=0, maxhappiness=0;
    int tmpcalori = 0, tmphappiness=0;
    while(cin>> num) {
        vector<int> calori;
        vector<int> happiness;
        vector<double> val;
        for(int i=0; i<num; ++i) {
            cin>>tmphappiness>>tmpcalori;
            calori.push_back(tmpcalori);
            happiness.push_back(tmphappiness);
        //    double tmp = (double)tmphappiness/tmpcalori;
        //    cout<<"tmp "<<tmp<<endl;
        //    val.push_back(tmp);
        }
        cin>>maxcalori;
//        std::cout << "The largest element is "  << *std::max_element(val.begin(), val.end()) << '\n';
//        double largest = *std::max_element(val.begin(), val.end());
//        std::cout << "The largest bound is "  << lower_bound(val.begin(), val.end(), largest)-val.begin() << '\n';
        int res = eat_food(calori, happiness, maxcalori, num);
        //cout<<"res is "<<res<<endl<<endl;
        cout<<res<<endl;
    }

    return 0;
}
