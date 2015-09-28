#include <iostream>
#include <string>
using namespace std;
int main()
{
    string origin, sub;
    while(cin>>origin>>sub) {
        int j = 0;
        for(int i=0; i<sub.length(); ++i) {
            if(j<origin.length() && sub[i] == origin[j])
                ++j;
        }
        if(j == origin.length())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
