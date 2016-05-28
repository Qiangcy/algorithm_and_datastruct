class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = numeric_limits<int>::lowest();
        for(int i=0; i<nums.size(); ++i) {
            sum = max(nums[i] , sum+nums[i]);
            res = max(sum , res);
        }
        return res;
    }
};

/* Time Limit Exceeded */
class Solution {
    public:
        int max_val = 0;
        vector<int> backup;
        int dp(vector<int>& nums, int start)
        {
            if(start >= nums.size())
                return 0;
            if(backup[start] != 0)
                return backup[start];
            for(int i=start; i<nums.size(); ++i) {
                for(int j=i; j<nums.size(); ++j) {
                    max_val = max(max_val, max_val+dp(nums, j+1));
                }
            }
            backup[start] = max_val;
            return max_val;
        }
        int maxSubArray(vector<int>& nums) {
            backup = vector<int>(nums.size(), 0);
            max_val = nums[0];
            return dp(nums, 0);
        }
};
