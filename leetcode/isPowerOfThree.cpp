class Solution {
    public:
        bool isPowerOfThree(int n) {
            while(n) {
                if(n == 1)
                    return true;
                else if(n%3 != 0)
                    return false;
                else
                    n /= 3;
            }
            return false;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        else if(n == 1)
            return true;
        else if(n%3 != 0)
            return false;
        return isPowerOfThree(n/3);
    }
};
