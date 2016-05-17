class Solution {
public:
    unordered_map<int, int> mymap;
    int climbStairs(int n) {
        if(n==0 || n==1)
            return 1;
        if(mymap[n])
            return mymap[n];
        mymap[n] =  climbStairs(n-1)+climbStairs(n-2);
        return mymap[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1)
            return 1;
        if(n == 2)
            return 2;

        int prev=1, next=1, all=2;
        for(int i=3; i<=n; ++i) {
            prev = next;
            next = all;
            all = prev + next;
        }

        return all;
    }
};
