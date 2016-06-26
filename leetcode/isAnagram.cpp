class Solution {
    public:
        bool isAnagram(string s, string t) {
            sort(begin(s), end(s));
            sort(begin(t), end(t));
            return s==t;
        }
};

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length())
                return false;
            unordered_map<char, int> mymap;
            for(int i=0; i<s.length(); ++i) {
                mymap[s[i]]++;
                mymap[t[i]]--;
            }
            for(auto &it : mymap) {
                if(it.second)
                    return false;
            }
            return true;
        }
};

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length())
                return false;
            char mymap[26] = {0};
            for(int i=0; i<s.length(); ++i) {
                mymap[s[i]-'a']++;
                mymap[t[i]-'a']--;
            }
            for(int i=0; i<26; ++i) {
                if(mymap[i])
                    return false;
            }
            return true;
        }
};
