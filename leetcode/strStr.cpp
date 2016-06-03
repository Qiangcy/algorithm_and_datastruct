class Solution {
public:
    int strStr(string haystack, string needle) {
        const int haystack_len = haystack.length();
        const int needle_len = needle.length();
        if(!needle_len)
            return 0;
        int i, j, tmp_i;
        /* hack: haystack_len-needle_len+1 */
        for(i=0; i<haystack_len-needle_len+1; ++i) {
            tmp_i = i;
            for(j=0; j<needle_len; ++j) {
                if(tmp_i >=haystack_len || haystack[tmp_i] != needle[j])
                    break;
                else
                    ++tmp_i;
            }
            if(j == needle_len)
                return i;
        }
        return -1;
    }
};
