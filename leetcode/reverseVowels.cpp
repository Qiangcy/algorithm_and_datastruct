class Solution {
    public:
        string reverseVowels(string s) {
            string vowerls = "aeiouAEIOU";
            for(int i=0,j=s.length()-1; i<j; ) {
                if(vowerls.find(s[i]) == string::npos) {
                    ++i;
                }
                if(vowerls.find(s[j]) == string::npos) {
                    --j;
                }
                if(vowerls.find(s[i])!=string::npos && vowerls.find(s[j])!=string::npos) {
                    if(s[i] != s[j]) {
                        swap(s[i], s[j]);
                    }
                    ++i; --j;
                }
            }
            return s;
        }
};

class Solution {
public:
    string reverseVowels(string s) {
        auto p1 = s.begin(), p2 = s.end() - 1;
        string vowels = "aeiouAEIOU";
        while(p1 < p2) {
            while((vowels.find(*p1) == string::npos) && (p1 < p2)) p1++;
            while((vowels.find(*p2) == string::npos) && (p1 < p2)) p2--;
            if(p1 < p2) swap(*p1, *p2);
            p1++;
            p2--;
        }
        return s;
    }
};

class Solution {
public:
    string reverseVowels(string s) {
        int i=0, j=s.length()-1;
        while(i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            /* pos	-	position at which to begin searching */

            /* need plus, as it just swap vowerls' place */
            if(i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
};
