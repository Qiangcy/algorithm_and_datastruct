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
bool cmp(queue<int> a, queue<int> b)
{
    return a.size() > b.size();
}

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most queues)
#else
    // add i/o method of specific testing system
#endif
    int queues, num, tmp, rescnt=1, sort_flag=1;
    string command, str;
    while(cin>>queues && queues!=0) {
        cout<<"Scenario #"<<rescnt++<<endl;
        //cout<<"queues is "<<queues<<endl;
        vector< vector<int> > members(queues);
        vector< queue<int> > team_queue(queues);
        for(int j=0; j<queues; ++j) {
            cin>>num;
            for(int i=0; i<num; ++i) {
                cin>>tmp;
                members[j].push_back(tmp);
                //cout<<"members push "<<j<<" is "<<tmp<<endl;
            }
        }
        //cout<<"new start"<<endl;
        while(cin>>command) {
            //cout<<"command is "<<command<<endl;
            if(command == "ENQUEUE") {
                //cout<<"In ENQUEUE"<<endl;
                if(!sort_flag) {
                    sort_flag = 1;
                }
                cin>>command;
                stringstream ss;
                ss<<command;
                ss>>tmp;
                for(int i=0; i<queues; ++i) {
                    //cout<<"i is "<<i<<" find tmp is "<<tmp<<endl;
                    vector<int>::iterator it = find(members[i].begin(), members[i].end(), tmp);
                    if(it != members[i].end()) {
                        team_queue[i].push(*it);
                        //cout<<"push "<<i<<" is "<<*it<<endl;
                    }
                }
            }else if(command == "DEQUEUE") {
                if(sort_flag) {
                    sort(team_queue.begin(), team_queue.end(), cmp);
                    sort_flag = 0;
                }
                for(int i=0; i<queues; ++i) {
                    //cout<<"team_queue["<<i<<"].size()"<<team_queue[i].size()<<endl;
                    if(team_queue[i].size()) {
                        cout<<team_queue[i].front()<<endl;
                        team_queue[i].pop();
                        break;
                    }
                }
            }else{
                break;
            }

        }
        cout<<endl;
    }
    return 0;
}
