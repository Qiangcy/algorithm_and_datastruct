#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int row, colum, num;
    string str;
    num = 1;
    while(cin>>row && row!=0) {
        cin>>colum;
        vector<string> a;
        for(int i=0; i<row; ++i) {
                cin>>str;
                a.push_back(str);
        }
        cout<<"puzzle #"<<num++<<endl;
        cout<<"Across"<<endl;
        for(int i=0; i<row; ++i) {
            if(a[i][0] != '*')
                cout<<i+1<<".";
            for(int j=1; j<colum; ++j) {
                if(a[i][j] != '*')
                    cout<<a[i][j];
            }
            cout<<endl;
        }

        cout<<"Down"<<endl;



    }
    return 0;
}
