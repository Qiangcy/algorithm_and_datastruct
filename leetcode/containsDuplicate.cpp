class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            if(nums.empty())
                return false;
            sort(begin(nums), end(nums));
            for(int i=0; i<nums.size()-1; ++i) {
                if(nums[i] == nums[i+1])
                    return true;
            }
            return false;
        }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(begin(nums), end(nums)).size();
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> my_map;
        for(auto &it : nums) {
            ++my_map[it];
            if(my_map[it] > 1)
                return true;
        }
        return false;
    }
}

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {

            unordered_map<int, bool> myMap;
            // unordered_multimap<int, bool> myMap;
            for (auto& num: nums) {
                if (myMap.find(num) != myMap.end())
                    return true;
                myMap.insert(make_pair(num, true));
            }
            return false;
        }
};
