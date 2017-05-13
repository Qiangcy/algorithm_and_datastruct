#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input3.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    int n=0, p=0, q=0;
    while(~scanf("%d %d %d", &n, &p, &q)) {
        int min=1, max=p, get=1;
        while(! (n>=min && n<=max)) {
            min += p;
            max += q;
//            cout<<"min ["<<min<<"]"<<" max["<<max<<"]"<<endl;
            ++get;
        }
        if(get%2 == 0)
            printf("WIN\n");
        else
            printf("LOST\n");
    }

}

