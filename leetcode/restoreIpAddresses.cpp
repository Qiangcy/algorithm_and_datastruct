/* Given "25525511135", */
/* return ["255.255.11.135", "255.255.111.35"] */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string> res;
        for(int i=1; i<=3; ++i) {
            for(int j=1; j<=3; ++j) {
                for(int k=1; k<=3; ++k) {
                    for(int l=1; l<=3; ++l) {
                    if(i+j+k+l != n)
                        continue;
                    int a = stoi(s.substr(0, i));
                    int b = stoi(s.substr(i, j));
                    int c = stoi(s.substr(i+j, k));
                    int d = stoi(s.substr(i+j+k, l));
                    if(a>255 || b>255 || c>255 || d>255)
                        continue;
                    string tmp = to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d);
                    if(tmp.length() == n+3)
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
};
