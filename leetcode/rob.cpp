/* M(k) = money at the kth house */
/* P(0) = 0 */
/* P(1) = M(1) */
/* P(k) = max(P(k−2) + M(k), P(k−1)) */
class Solution {
    public:
        unordered_map<int, int> cache;
        int dp(vector<int>& nums, int i) {
            if(i < 0)
                return 0;
            else if(i == 0)
                return nums[0];
            else if(cache[i])
                return cache[i];
            else {
                int tmp = max(dp(nums, i-2)+nums[i], dp(nums, i-1));
                cache[i] = tmp;
                return tmp;
            }
        }
        int rob(vector<int>& nums) {
            return dp(nums, nums.size()-1);
        }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(i%2 == 0)
                a = max(b, a+nums[i]);
            else
                b = max(a, b+nums[i]);
        }
        return max(a, b);
    }
};
