#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        char *str=(char*)malloc(100);
        scanf("%s", str);
        int sum=0;
        for(int i=0; str[i]; ++i) {
            for(int k=1; str[i]=='O'; ++k) {
                sum+=k;
                ++i;
            }
        }
        printf("%d\n", sum);
    }
}

/*
#include <iostream>
#include <stdio.h>
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
        printf("%d\n", sum);
        //        cout<<sum<<endl;
    }
}
*/
