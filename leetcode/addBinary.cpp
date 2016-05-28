class Solution {
public:
    void init(string& s, int n) {
        for(int i=0; i<n; ++i)
            s.insert(begin(s), '0');
    }

    string addBinary(string a, string b) {
        const int a_len = a.length(), b_len = b.length();
        int len = 0;
        if(a_len < b_len) {
            init(a, b_len-a_len);
            len = b_len;
        }else if(a_len > b_len) {
            init(b, a_len-b_len);
            len = a_len;
        }else {
            len = a_len;
        }

        int cnt = 0;
        for(int i=len-1; i>=0; --i) {
            int new_cnt = 0;
            int tmp_a = (a[i]=='0'?0:1);
            int tmp_b = (b[i]=='0'?0:1);
            int res = tmp_a^tmp_b;
            if(tmp_a && tmp_b)
                new_cnt = 1;
            if(res && cnt)
                new_cnt = 1;
            res = res^cnt;
            a[i] = (res==1?'1':'0');
            cnt = new_cnt;
        }
        if(cnt)
            a.insert(begin(a), '1');
        return a;
    }
};
