#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double repre(char c)
{
    switch (c)
    {
        case 'C': return 12.01;
        case 'H': return 1.008;
        case 'O': return 16.00;
        case 'N': return 14.01;
        default: return 0;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin>>str;
        double sum = 0, ans=0, current_num=0, mass_num=0;
        for(int i=0; str[i]; ++i) {
            current_num = repre(str[i]);
            sum = 0;
            if(current_num != 0)
                mass_num = current_num;

            while('0' <=str[i+1] && str[i+1]<= '9' ) {
                sum = sum*10 + (str[i+1]-'0');
                ++i;
            }
            if(sum == 0)
                sum = 1;
            ans = ans+ sum*mass_num;
        }
        cout<<setiosflags(ios::fixed)<<setprecision(3)<<ans<<endl;

    }
}
