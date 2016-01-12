#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }

vector<int> lens(181, -1);
int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    string x, single_word;
    int lines=0, num=0;
    vector< vector<string> > word;
    while(getline(cin, x)) {
        vector<string> single;
        stringstream ss(x);
        while(ss>>single_word)  {
            single.push_back(single_word);
            int tmp = single_word.length();
//            cout<<"single_word is "<<single_word<<" len is "<<single_word.length()<<endl;
            lens[num] = std::max(lens[num], tmp);
            num++;
        }
        word.push_back(single);
        lines++;
    }
//    cout<<"lines is "<<lines<<endl;
    for(int i =0 ; i<lines; ++i) {
        vector<string>::iterator it = word[i].begin();
        int j = 0;
        for(; it!=word[i].end(); ++it) {
            cout<<*it;
            if(it+1!=word[i].end()) {
 //               cout<<"lnes[j] "<<lens[j]<<"  it->length();  "<<it->length()<<endl;
                int diff = lens[j]-it->length();
                for(int k=0; k<abs(diff); ++k)
                    cout<<" ";
                cout<<" ";
            }
            j++;
        }
        cout<<endl;
    }
    return 0;
}
/*
 *
 * #include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    string line;
    vector< vector<string> > ret;
    int mx[256] = {};
    while (getline(cin, line)) {
        stringstream sin(line);
        vector<string> v;
        string x;
        while (sin >> x) {
            v.push_back(x);
            mx[v.size()] = max(mx[v.size()], (int) x.length());
        }
        ret.push_back(v);
    }
    for (int i = 1; i < 256; i++)
        mx[i] += mx[i - 1] + 1;
    for (int i = 0; i < ret.size(); i++) {
        vector<string> &v = ret[i];
        int pos = 0;
        for (int j = 0; j < v.size(); j++) {
            while (pos < mx[j]) putchar(' '), pos++;
            printf("%s", v[j].c_str());
            pos += v[j].length();
        }
        puts("");
    }
    return 0;
}
 */
