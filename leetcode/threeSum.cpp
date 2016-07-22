class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;
            if(nums.size() < 3)
                return res;
            sort(begin(nums), end(nums));
            for(int i=0; i<nums.size(); ++i) {
                int small_sum = -nums[i];
                int front = i+1, rear = nums.size()-1;
                while(front < rear) {
                    if(nums[front] + nums[rear] > small_sum) {
                        --rear;
                    }else if(nums[front] + nums[rear] < small_sum) {
                        ++front;
                    }else {
                        vector<int> tmp = {nums[front], nums[rear], nums[i]};
                        res.push_back(tmp);
                        while(front<rear && nums[front]==tmp[0]) ++front;
                        while(front<rear && nums[rear]==tmp[1]) --rear;
                    }
                }
                // Processing duplicates of Number 1
                while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                    i++;
            }
            return res;
        }
};
