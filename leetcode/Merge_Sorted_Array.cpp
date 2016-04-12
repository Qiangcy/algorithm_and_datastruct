class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(nums1.size() > m) {
            nums1.pop_back();
        }
        for(auto &it : nums2) {
            nums1.push_back(it);
        }
        sort(begin(nums1), end(nums1));
    }
};
