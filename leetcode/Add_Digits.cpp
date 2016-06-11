class Solution {
public:
    int addDigits(int num) {
        int res = 0;
        while(num > 0) {
            res += num%10;
            num /= 10;
        }
        if(res > 9)
            return addDigits(res);
        else
            return res;
    }
};

class Solution {
    public:
        int addDigits(int num) {
            int res;
            do {
                res = 0;
                while(num > 0) {
                    res += num%10;
                    num /= 10;
                }
                num = res;
            }while(res > 9);
            return res;
        }
};

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};
