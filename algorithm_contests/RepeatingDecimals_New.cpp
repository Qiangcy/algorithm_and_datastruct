#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int a, b;
    while(cin>>a>>b) {
        int num_of_digits=0, origin_a = a;
        vector<int> vec, keep_a;
        a %= b;
        keep_a.push_back(-1);
        vector<int>::iterator it=keep_a.begin();
        int i = 0;
        while(1) {
            it = find(keep_a.begin(), keep_a.end(), a);
            if(it != keep_a.end()) {
                num_of_digits = keep_a.end()-it;
                break;
            }
            ++i;
            num_of_digits++;
            keep_a.push_back(a);
            a *= 10;
            vec.push_back(a/b);
            a %= b;
        }

        cout<<origin_a<<"/"<<b<<" = "<<origin_a/b<<".";
        int k = 0;
        for(it=vec.begin(); it!=vec.end(); ++it,++k) {
            if(k == i-num_of_digits)
                cout<<"(";
            if(k == 50) {
                cout<<"...";
                break;
            }
            cout<<*it;
        }
        cout<<")"<<endl;
        cout<<"   "<<num_of_digits<<" = number of digits in repeating cycle"<<endl<<endl;
    }
    return 0;
}
