class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto &it : nums)
            res ^= it;
        return res;
    }
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = accumulate(begin(nums), end(nums), 0, bit_xor<int>());
        /* for(auto it : nums) */
        /*     res ^= it; */
        res &= -res;

        vector<int> appear_once(2, 0);
        for(auto it : nums) {
            if((it & res) == 0)
                appear_once[0] ^= it;
            else
                appear_once[1] ^= it;
        }
        return appear_once;
    }
};
