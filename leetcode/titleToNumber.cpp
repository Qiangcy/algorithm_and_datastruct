class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int res = 0;
        int pow_res = 1;
        for(int i=0; i<len; ++i) {
            res = res + (s[len-i-1]-'A'+1) * pow_res;
            pow_res *= 26;
        }
        return res;
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        int i = 0;
        while(n) {
            /* res[i++] = n%26-1+'A'; */
            char c;
            if(n%26 == 0) {
                c = 'Z';
                n--;
            } else {
                c = n%26-1+'A';
            }
            n /= 26;
            res.insert(0, 1, c);
        }
        return res;
    }
};

string convertToTitle(int n) {
    string res;
    while(n>=1){
        res=(char)('A'+(n-1)%26)+res;
        n=(n-1)/26;
    }
    return res;
}
