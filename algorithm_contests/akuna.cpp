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

enum trade_type {BUY, SELL};
enum order_type {IOC, GFD};

class record {
    public:
        record(string a, string b, int price, int quantity) {
            this->trade = (a=="BUY"?BUY:SELL);
            this->order = (b=="IOC"?IOC:GFD);
            this->price = price;
            this->quantity = quantity;
        }
        trade_type trade;
        order_type order;
        int price;
        int quantity;
};

struct {
    bool operator()(record* rec1, record* rec2)
    {
        if(rec1->trade > rec2->trade) {
            return 1;
        }else {
            return rec1->price > rec2->price;
        }
    }

} customGreater;

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
#endif
    string trade, order;
    int price, quantity;
    vector<record*> record_orders;
    while(cin>>trade>>order>>price>>quantity) {
        int n = record_orders.size();
        record *tmp = new record(trade, order, price, quantity);

        if(n == 0) {
            if(tmp->order != IOC)
                record_orders.push_back(tmp);
        }else {
            if(tmp->order == IOC) {
                if(tmp->trade != record_orders[n-1]->trade) {//SELL or BUY
                    int diff = record_orders[n-1]->quantity - tmp->quantity;
                    if(diff <= 0) {
                        record_orders.pop_back();
                    }else {
                        record_orders[n-1]->quantity = diff;
                    }
                }
            }else {
                if(tmp->trade == record_orders[n-1]->trade) {
                    if(tmp->price == record_orders[n-1]->price)
                        record_orders[n-1]->quantity += tmp->quantity;
                    else
                        record_orders.push_back(tmp);
                }else {
                    if((tmp->trade==BUY && tmp->price < record_orders[n-1]->price) ||
                            (tmp->trade==SELL && record_orders[n-1]->price < tmp->price)) {
                        record_orders.push_back(tmp);
                    }else {
                        int diff = record_orders[n-1]->quantity - tmp->quantity;
                        if(diff == 0) {
                            record_orders.pop_back();
                        }else if(diff < 0) {
                            record_orders.pop_back();
                            tmp->quantity = -diff;
                            record_orders.push_back(tmp);
                        }else {
                            record_orders[n-1]->quantity = diff;
                        }
                    }
                }
            }
        }
    }

    /* cout<<endl; */
    /* for(auto it : record_orders) */
    /*     it->output_single(); */
    sort(begin(record_orders), end(record_orders), customGreater);

    cout<<"SELL:"<<endl;
    auto it = begin(record_orders);
    while(it!=end(record_orders) && (*it)->trade==SELL) {
        cout<<(*it)->price<<" "<<(*it)->quantity<<endl;
        it++;
    }
    cout<<"BUY:"<<endl;
    while(it!=end(record_orders) && (*it)->trade==BUY) {
        cout<<(*it)->price<<" "<<(*it)->quantity<<endl;
        it++;
    }
    return 0;
}
