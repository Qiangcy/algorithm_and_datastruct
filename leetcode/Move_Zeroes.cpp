class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            const int len = nums.size();
            int i=0, j=0;
            while(j < len) {
                if(!nums[i]) {
                    if(nums[j] != 0) {
                        swap(nums[i], nums[j]);
                        ++i;
                    }
                    ++j;
                }else {
                    ++i; ++j;
                }
            }
        }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
