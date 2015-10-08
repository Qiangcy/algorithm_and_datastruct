#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int get_second( pair<char, int> i  ){return i.second;  }// cout<<"i.second: "<<i.second<<endl;
int cmp(int a, int b) {return a>b;}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int num, len;
        cin>>num>>len;
        vector< vector<char> > vec(num, vector<char>(len));
        for(int i=0; i<num; ++i) {
            for(int j=0; j<len; ++j) {
                cin>>vec[i][j];
            }
        }

        int i = 0;
        vector<char> res(len);
        int hamming_distance = 0;
        for(int j=0; j<len; ++j) {
            map<char,int> keylist;
            for(int i=0; i<num; ++i) {
                keylist[vec[i][j]]++;
            }
            vector<int> v(keylist.size());
            transform(keylist.begin(), keylist.end(), v.begin(), get_second);
            sort(v.begin(), v.end(), cmp);
            bool dupicate = 0;
            if(v[0] == v[1])
                dupicate = 1;
            //for (int i=0; i<v.size(); i++)
            //    cout<<"v[i] is "<<v[i]<<endl;
            char smallest = keylist.begin()->first;
            for(map<char,int>::iterator it = keylist.begin(); it!=keylist.end(); ++it) {
                if(it->second==v[0]) {
                    if(!dupicate) {
                        //                        cout<<"v[0] is "<<v[0]<<" it->first: "<<it->first<<endl;
                        res[i++] = it->first;
                        break;
                    }else {
                        if(it->first < smallest) {
                            smallest = it->first;
                        }
                    }
                }
            }
            if(dupicate)
                res[i++] = smallest;

            for(map<char,int>::iterator it = keylist.begin(); it!=keylist.end(); ++it) {
                //cout<<"count  *it : "<<it->first<<endl;
                if(it->first != res[i-1]) {
                    hamming_distance += it->second;
                    //cout<<"hamming_distance is "<<hamming_distance<<endl;
                }
            }
        }
        for(int k=0; k<i; ++k)
            cout<<res[k];
        cout<<endl<<hamming_distance<<endl;
        //cout<<endl<<"res end"<<endl<<endl;
    }
}
