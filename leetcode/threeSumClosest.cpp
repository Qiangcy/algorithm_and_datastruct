class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT_MAX, diff = INT_MAX;
        sort(begin(nums), end(nums));
        for(int i=0; i<nums.size(); ++i) {
            int small_sum = target - nums[i];
            int front = i+1, rear = nums.size()-1;
            while(front < rear) {
                if(abs(target - (nums[rear]+nums[front]+nums[i])) < diff) {
                    diff = abs(target - (nums[rear]+nums[front]+nums[i]));
                    closest = nums[rear]+nums[front]+nums[i];
                }
                if(nums[front] + nums[rear] < small_sum) {
                    ++front;
                }else if(nums[front] + nums[rear] > small_sum) {
                    --rear;
                }else {
                    return target;
                }
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1])
                ++i;
        }
        return closest;
    }
};
