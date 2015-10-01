#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int get_second( pair<char, int> i  ){ return i.second;  }

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

//        cout<<"finish"<<endl;
//        for(int i=0; i<num; ++i) {
//            for(int j=0; j<len; ++j) {
//                cout<<vec[i][j]<<" ";
//            }
//        }

        vector<char>::iterator it;
        for(int j=0; j<len; ++j) {
            map<char,int> keylist;
            for(int i=0; i<num; ++i) {
                keylist[vec[i][j]]++;
                cout<<keylist[vec[i][j]]<<" %"<<endl;
            }
            cout<<" keylist.size() : "<< keylist.size()<<endl;
            vector<char> v( keylist.size()  );
            transform( keylist.begin(), keylist.end(), v.begin(), get_second  );
            for (int i=0; i<v.size(); i++)
                cout << v[i] << endl;
            sort( v.begin(), v.end()  );
            for (int i=0; i<v.size(); i++)
                cout << v[i] << endl;
        }



    }
}





