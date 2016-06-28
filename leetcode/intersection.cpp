class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> mymap;
            vector<int> res;
            for(auto it : nums1) {
                mymap[it] = 1;
            }
            for(auto it :nums2) {
                if(mymap.find(it) != end(mymap) && mymap[it]) {
                    mymap[it]--;
                    res.push_back(it);
                }
            }
            return res;
        }
};

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> myset(begin(nums1), end(nums1));
            vector<int> res;
            for(auto it : nums2) {
                if(myset.count(it)) {
                    res.push_back(it);
                    myset.erase(it);
                }
            }
            return res;
        }
};
