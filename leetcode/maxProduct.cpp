class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> hash(words.size());
        int res = 0;
        for(int i=0; i<words.size(); ++i) {
            for(auto it : words[i])
                hash[i] |= 1<<(it-'a');
            for(int j=0; j<i; ++j) {
                if((hash[j] & hash[i])== 0) {
                    res = max(res, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return res;
    }
};
