class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, i;
        for(i=0; i<nums.size(); ++i) {
            sum += (i-nums[i]);
        }
        sum += i;
        return sum;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, tmp = 0;
        for(auto &it : nums)
            sum += it;
        for(int i=0; i<=nums.size(); ++i)
            tmp += i;
        return tmp-sum;
    }
};
