class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash, reflect;
        for(int i=0; i<s.length(); ++i) {
            if(hash.find(s[i])==end(hash) && reflect.find(t[i])==end(reflect)) {
                hash[s[i]] = t[i];
                reflect[t[i]] = s[i];
            }else {
                if(hash[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};
