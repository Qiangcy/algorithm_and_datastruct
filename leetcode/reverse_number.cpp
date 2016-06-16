class Solution {
    public:
        int reverse(int x) {
            long int sum =0;
            while(x) {
                sum = sum*10 + x%10;
                x /= 10;
            }
            if(sum>2147483647 || sum<-2147483648)
                return 0;
            return sum;
        }
};
