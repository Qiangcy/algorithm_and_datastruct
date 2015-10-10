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
            for(int i=0; i<num; ++i)
                keylist[vec[i][j]]++;
            vector<int> v(keylist.size());
            transform(keylist.begin(), keylist.end(), v.begin(), get_second);
            sort(v.begin(), v.end(), cmp);
            bool dupicate = 0;
            if(v[0] == v[1])
                dupicate = 1;
            //for (int i=0; i<v.size(); i++)
            //    cout<<"v[i] is "<<v[i]<<endl;
            map<char,int>::iterator it = keylist.begin();
            if(dupicate) {
                res[i++] = it->first;
            }else{
                for(; it!=keylist.end(); ++it) {
                    if(it->second==v[0]) {
                        res[i++] = it->first;
                        break;
                    }
                }
            }
            hamming_distance += num - v[0];
        }
        //        for(int k=0; k<i; ++k)
        //            cout<<res[k];
        for(int k=0; res[k]; ++k)
            putchar(toupper(res[k]));
        cout<<endl<<hamming_distance<<endl;
        //cout<<endl<<"res end"<<endl<<endl;
    }
}

/*
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int testcase;
    int n, m;
    char DNA[64][1024];
    scanf("%d", &testcase);
    while (testcase--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", DNA[i]);
        int hh = 0;
        char ret[1024] = {}, cc[] = "ACGT";
        for (int i = 0; i < m; i++) {
            int cnt[4] = {}, mx = 0;
            for (int j = 0; j < n; j++)
                cnt[find(cc, cc+4, DNA[j][i]) - cc]++;

            for (int j = 0; j < 4; j++) {
                if (cnt[j] > cnt[mx])
                    mx = j;
            }
            ret[i] = cc[mx], hh += n - cnt[mx];

        }
        printf("%s\n%d\n", ret, hh);
    }
    return 0;
}
*/
