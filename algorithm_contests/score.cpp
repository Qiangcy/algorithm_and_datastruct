#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        int sum=0;
        for(int i=0; str[i]; ++i) {
            for(int k=1; str[i]=='O'; ++k) {
                sum+=k;
                ++i;
            }
        }
        cout<<sum;
    }
}
