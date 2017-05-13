class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0xFFFFFFFF;
//        for(int i=0; i<32; ++i) {
//            res = res ^ 1;
//            res >>= 1;
//        }
    /* for(int i=0; i<32; ++i) { */
        /*     if(res&1) */
        /*         cout<<1; */
        /*     else */
        /*         cout<<0; */
        /*     res >>= 1; */
        /* } */
        /* cout<<endl; */
        res >>= 31;
        for(int i=0; i<32; ++i) {
            res = res & (n&1);
            n >>= 1;
            res <<= 1;
        }
        return res;
    }
};
