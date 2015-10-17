#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string str, encrypt_result;
    while(cin>>str>>encrypt_result) {
        vector<int> a(30, 0);
        vector<int> b(30, 0);
        for(int i=0; i<str.length(); ++i) {
            a[str[i]-'A']++;
            b[encrypt_result[i]-'A']++;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a == b)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
