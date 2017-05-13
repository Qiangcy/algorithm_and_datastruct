class Solution {
    public:
        int divide(int dividend, int divisor) {
            if(!dividend || !divisor)
                return 0;
            if(dividend*divisor>0 && dividend<divisor)
                return 0;
            int res = 0;
            bool flag = 0;
            if(dividend<0 && divisor>0) {
                dividend = -dividend;
                flag = 1;
            }else if(dividend>0 && divisor<0) {
                divisor = -divisor;
                flag = 1;
            }else if(dividend<0 && divisor<0) {
                dividend = -dividend;
                divisor = -divisor;
            }
            while(dividend - divisor >= 0) {
                dividend -= divisor;
                ++res;
            }
            return flag==0?res:-res;
        }
};
