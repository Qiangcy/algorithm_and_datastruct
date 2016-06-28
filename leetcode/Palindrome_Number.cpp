class Solution {
public:
    bool isPalindrome(int x) {
        int res = 0;
        if(x < 0)
            return false;
        int origin = x;
        while(x) {
            int tmp = x%10;
            res = res*10 + tmp;
            x /= 10;
        }
        /* cout<<"origin is "<<origin<<" res is "<<res/10<<endl; */
        return res==origin;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10==0))
            return false;
        int sum = 0;
        while(x > sum) {
            sum = sum*10+x%10;
            x /= 10;
        }
        return x==sum || x==sum/10;
    }
};
