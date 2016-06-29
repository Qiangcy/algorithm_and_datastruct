/* Input: numbers={2, 7, 11, 15}, target=9 Output: index1=1, index2=2 */
class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> res;
            unordered_map<int ,int> my_map;
            for(int i=0; i<numbers.size(); ++i)
                my_map[numbers[i]] = i;
            for(int i=0; i<numbers.size(); ++i) {
                int number_to_find = target-numbers[i];
                if(my_map.find(number_to_find)!=end(my_map) && my_map[number_to_find]!=i) {
                    res.push_back(i);
                    res.push_back(my_map[number_to_find]);
                    return res;
                }
            }
            return res;
        }
};

/* Input: numbers={2, 7, 11, 15}, target=9 Output: index1=1, index2=2 */
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> imap;

            for (int i = 0;; ++i) {
                auto it = imap.find(target - nums[i]);

                if (it != imap.end())
                    return vector<int> {i, it->second};

                imap[nums[i]] = i;
            }
        }
};
