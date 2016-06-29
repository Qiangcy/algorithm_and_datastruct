class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int res = 0;
            for(int i=0; i<32; ++i) {
                if(n&1)
                    res++;
                n>>=1;
            }
            return res;
        }
};

class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int count = 0;

            while (n) {
                n &= (n - 1);
                count++;
            }

            return count;
        }
};
