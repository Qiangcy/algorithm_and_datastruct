#include <iostream>
#include <string>
using namespace std;

int lessfun(string str, int old, int pos)
{
    int len = str.length();
    for(int i=0; i<len; ++i) {
        if(str[(old+i)%len] != str[(pos+i)%len])
            return str[(pos+i)%len] < str[(old+i)%len];
    }
    return 0;
}

int main()
{
    int time = 0;
    cin>>time;
    string str;
    while(time--){
        cin>>str;
        int rec=0;
        for(int i=1; i<str.length(); ++i) {
            if(lessfun(str, rec, i)) {
                rec = i;
            }
        }

        for(int i=0; i<str.length(); ++i) {
            cout<<str[(rec+i)%str.length()];
        }
        cout<<endl;
    }
}

