class Solution {
    public:
        bool isPalindrome(string s) {
            const int len = s.length();
            if(!len)
                return true;
            int start = 0, end = len-1;
            for(;;) {
                if(start == end-1) {
                    if(isalnum(s[start]) && isalnum(s[end])) {
                        if(tolower(s[start]) == tolower(s[end]))
                            return true;
                        else
                            return false;
                    }else {
                        return true;
                    }
                }else if(start == end) {
                    return true;
                }

                if(isalnum(s[start]) && isalnum(s[end])) {
                    if(tolower(s[start]) == tolower(s[end])) {
                        ++start;
                        --end;
                    }else {
                        return false;
                    }
                }else if(!isalnum(s[start])) {
                    ++start;
                }else if(!isalnum(s[end])) {
                    --end;
                }
            }
        }
};
