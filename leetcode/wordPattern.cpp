class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream stream(str);
        unordered_map<string, char> hash;
        unordered_map<char, string> reflect;
        int i = 0;
        while(i<pattern.length() && stream >> str) {
            if(hash.find(str)==end(hash) && reflect.find(pattern[i])==end(reflect)) {
                hash[str] = pattern[i];
                reflect[pattern[i]] = str;
            }else {
                if(hash[str] != pattern[i])
                    return false;
            }
            ++i;
        }
        if(stream >> str || i!=pattern.length())
            return false;
        return true;
    }
};
