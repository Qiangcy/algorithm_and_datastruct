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
    int singleNumber(vector<int>& nums) {
        const int vec_size = nums.size();
        if(!vec_size)
            return 0;
        int a = nums[0];
        for(int i=1; i<vec_size; ++i)
            a ^= nums[i];
        return a;
    }
};
