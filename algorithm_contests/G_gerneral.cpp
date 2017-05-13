#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }

int z =0;
int n=0;
//void order_clear()
//{
//    vector<int>::iterator it = order.begin();
//    for( ; it!=order.end(); ++it)
//        *it = -7;
//}
//void leader_clear()
//{
//    vector<int>::iterator it = leader.begin();
//    for( ; it!=leader.end(); ++it)
//        *it = -1;
//}
void cout_order(vector<int> &order)
{
    vector<int>::iterator it = order.begin();
    for( ; it!=order.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
}
bool have_leader(int solder, vector<int> &order)
{
    vector<int>::iterator it = order.begin();
    for( ; it!=order.end(); ++it) {
        if(*it == solder) {
            cout<<"soder found "<<*it<<" "<<endl;
            return true;
        }
    }
    return false;
}

void thirst(int start, vector<int> &order, vector<int> &leader)
{
    if(z >= n) {
        return;
    }
    if(start >= n) {
        return;
    }
    cout<<"Start is "<<start<<endl;
    //cout_order();
    for(int i=start; i<=n; ++i) {
        if(have_leader(leader[i-1], order) == false) {
            order[z++] = i;
            cout_order(order);
            thirst(i+1, order, leader);
        order[z--] = -7;
        }
    }
    //thirst(start+1);
}

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input2.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    while(cin>>n) {
        vector<int> leader(n-1, -7);
        vector<int> order(n, -1);
        int tmp;
        for(int i=1; i<n; ++i) {
            cin>>tmp;
//            cout<<"tmp "<<tmp<<endl;
            leader.push_back(tmp);
        }
        for(int i=1; i<=n; ++i) {
            z = 1;
            order.clear();
            thirst(i, leader, order);
        }
        char x;cin>>x;
    }

    return 0;
}
