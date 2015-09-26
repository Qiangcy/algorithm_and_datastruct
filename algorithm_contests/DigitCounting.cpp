#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int a[10];
    while(t--) {
        memset(a, 0, sizeof(a));
        int num;
        cin>>num;
        for(int i=1;i<=num;++i) {
            int tmp = i;
            while(tmp != 0) {
                a[tmp%10]++;
                tmp /= 10;
            }
        }

        for(int i=0; i<9; ++i)
            cout<<a[i]<<" ";
        cout<<a[9]<<endl;
    }
}
