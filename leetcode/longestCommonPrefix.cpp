class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(!strs.size() || !strs[0].length())
                return "";
            for(int i=0; i<strs[0].length(); ++i) {
                for(int j=1; j<strs.size(); ++j) {
                    if(strs[j][i] != strs[0][i])
                        return strs[0].substr(0, i);
                }
            }
            return strs[0];
        }
};