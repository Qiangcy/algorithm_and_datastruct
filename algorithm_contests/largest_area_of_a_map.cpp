#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }
int row, col;
int sum , max_res;

void print(vector< vector<int> > pic, int row, int col)
{
    cout<<endl;
    for(int i=0; i<row; ++i) {
        for(int j=0; j<col; ++j) {
            cout<<pic[i][j]<<" ";
        }
        cout<<endl;
    }

}

void dfs(vector< vector<int> > &pic, int i, int j)
{
    //    cout<<"inside i "<<i<<" j "<<j<<" "<<endl;
    if(i<0 || j<0 || i>=row || j>=col)
        return;
    if(!pic[i][j] || pic[i][j]==-1)
        return;

    if(pic[i][j] > 0) {
        sum++;
        pic[i][j] = -1;
        //print(pic, row, col);
    }
    dfs(pic, i, j+1);
    dfs(pic, i+1, j);
    dfs(pic, i, j-1);
    dfs(pic, i-1, j);
    return;
}

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    while(cin>>row>>col) {
        max_res = 0;
        vector< vector<int> > pic(row, vector<int> (col));
        for(int i=0; i<row; ++i)
            for(int j=0; j<col; ++j)
                cin>>pic[i][j];
        print(pic, row, col);
        for(int i=0; i<row; ++i) {
            for(int j=0; j<col; ++j) {
                //cout<<"i "<<i<<" j "<<j<<" "<<endl;
                if(sum > max_res)
                    max_res = sum;
                sum = 0;
                if(pic[i][j] > 0)
                    dfs(pic, i, j);
            }
        }
        print(pic, row, col);
        cout<<"sum is "<<max_res<<endl;
    }
    return 0;
}
