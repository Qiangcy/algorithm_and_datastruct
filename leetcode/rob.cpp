/* M(k) = money at the kth house */
/* P(0) = 0 */
/* P(1) = M(1) */
/* P(k) = max(P(k−2) + M(k), P(k−1)) */
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n);
            if(n == 0)
                return 0;
            if(n == 1)
                return nums[0];
            else if(n == 2)
                return max(nums[0], nums[1]);
            else {
                dp[0] = nums[0];
                dp[1] = max(nums[0], nums[1]);
                for(int i=2; i<n; ++i) {
                    dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
                }
            }
            return dp[n-1];
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
