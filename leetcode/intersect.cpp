class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            vector<int> res;
            if(nums1.empty() || nums2.empty())
                return res;
            sort(begin(nums1), end(nums1));
            sort(begin(nums2), end(nums2));
            for(int i=0,j=0; i<nums1.size() && j<nums2.size(); ) {
                if(nums1[i] == nums2[j]) {
                    res.push_back(nums2[j]);
                    ++j;
                    ++i;
                }else if(nums1[i] < nums2[j]) {
                    ++i;
                }else if(nums1[i] > nums2[j]) {
                    ++j;
                }
            }
            return res;
        }
};

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> mymap;
            vector<int> res;
            for(auto it : nums1) {
                mymap[it]++;
            }
            for(auto it : nums2) {
                if(--mymap[it] >= 0) {
                    res.push_back(it);
                }
            }
            return res;

        }
}

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            nums1.erase(set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums1.begin()), nums1.end());
            return nums1;

        }
};
