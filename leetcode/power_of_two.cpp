class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n || n<0)
            return false;
        int sum_of_one = 0;
        for(int i=0; i<32; ++i) {
            sum_of_one += n&1;
            if(sum_of_one > 1)
                return false;
            n >>= 1;
        }
        return true;
    }
};


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n || n<0)
            return false;
        bool flag = 0;
        //int t = ceil(log2(n));
        for(int i=0; i<32; ++i) {
            if(n&1 == 1) {
                if(!flag)
                    flag = true;
                else
                    return false;
            }
            n >>= 1;
        }
        return flag;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n)
            return false;

        int t = floor(log2(n));
        if(pow(2, t) == n)
            return true;
        return false;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n || n<0)
            return false;

        int t = floor(log2(n));
        int b = ceil(log2(n));
        if(b-t == 0)
            return true;
        return false;
    }
};

