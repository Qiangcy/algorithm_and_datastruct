class Solution {
public:
    string reverseString(string s) {
        for(int i=0,j=s.length()-1; i<j; ++i,--j)
            swap(s[i], s[j]);
        return s;
    }
};

class Solution {
public:
    string reverseString(string s) {
        const int len = s.length();
        if(!len)
            return s;
        char tmp = ' ';
        for(int i=0,j=len-1; i!=j; ++i,--j) {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            if(i+1 == j)
                break;
        }
        return s;
    }
};
