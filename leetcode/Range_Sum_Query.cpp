class NumArray {
    public:
        vector<int> hash;
        NumArray(vector<int> &nums) {
            hash = vector<int>(nums.size()+1);
            hash[0] = 0;
            int sum = 0;
            for(int i=0; i<nums.size(); ++i) {
                sum += nums[i];
                hash[i+1] = sum;
            }
        }

        int sumRange(int i, int j) {
            return hash[j+1]- hash[i];
        }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
