#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }

int main(void)
{
    int times;
    while(scanf("%d", &times) && times!=-1) {
        for(int i=0; i<times; ++i) {
            int D, I;
            cin>>D>>I;
            int all = (1<<D);
            vector<int> trees(all, 0);
            int k = 1, tmp=0;

            for(int j=0; j<I; ++j) {
                k = 1;
                for(int i=0; i<D-1; ++i) {
                    tmp = k;
                    k = trees[k]?2*k+1:2*k;
                    trees[tmp] = !trees[tmp];
                }
                //cout<<"a round"<<endl<<endl;
            }
            printf("%d\n", k);
//            cout<<k<<endl;
        }
    }
    return 0;
}
