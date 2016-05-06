#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }

class point {
    public:
        int x;
        int y;
        point(int x2, int y2)
        {
            x = x2;
            y = y2;
        }
};
class Solution {
    public:
        void travel(stack<point> &mystack, int m, int n, int &res)
        {
            while(!mystack.empty()) {
                point t = mystack.top();
                mystack.pop();
                if(t.x==m-1 && t.y==n-1) {
                    res++;
                    return;
                }
                if(t.x+1 < m) {
                    point tmp = point(t.x+1, t.y);
                    mystack.push(tmp);
                    travel(mystack, m, n, res);
                }
                if(t.y+1 < n) {
                    point tmp = point(t.x, t.y+1);
                    mystack.push(tmp);
                    travel(mystack, m, n, res);
                }
            }
            return ;
        }
        int uniquePaths(int m, int n) {
            stack<point> mystack;
            point t = point(0, 0);
            mystack.push(t);
            int res = 0;
            travel(mystack, m, n, res);
            return res;
        }
};
int main(void)
{
    Solution p;
    cout<<p.uniquePaths(23, 12)<<endl;
    return 0;
}
