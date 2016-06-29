class Solution {
    public:
        bool isHappy(int n) {
            /* according to test, 1000 can be 6 */
            for(int i=0; i<8; ++i) {
                int res = 0;
                cout<<" n is "<<n<<endl;
                while(n) {
                    res += pow(n%10, 2.0);
                    n /= 10;
                }
                n = res;
            }
            return n==1;
        }
};

class Solution {
    public:
        bool isHappy(int n) {
            /* according to test, 1000 can be 6 */
            unordered_map<int, bool> hash;
            while(n!=1){
                int res = 0;
                hash[n] = 1;
                /* cout<<" n is "<<n<<endl; */
                while(n) {
                    res += pow(n%10, 2.0);
                    n /= 10;
                }
                if(hash.find(res) != end(hash)) {
                    break;
                }
                n = res;
            }
            return n==1;
        }
};
