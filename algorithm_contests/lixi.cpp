#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double origin= 0, saved_days=0;
    double e=0, f=0, grow=0;
    double suma=0, sumb=0;
    for(int i=0; i<n; ++i) {
        cin>>origin>>saved_days>>e>>f>>grow;
//        cout<<"saved_days"<<saved_days<<endl;
//        cout<<"f "<<f<<endl;
//        cout<<"e "<<e<<endl;
//        cout<<"grow "<<grow<<endl;
//
        suma = origin*(1 + e/100 * saved_days/365);
//        cout<<"or "<<suma<<endl;
        suma =  suma*(1+grow/100);

        sumb =origin*(1+f/100*(saved_days+365)/365);
        cout<<suma<<endl<<sumb<<endl;
    }
}
