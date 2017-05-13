class Solution {
    public:
        int countNumbersWithUniqueDigits(int n) {
            if(n == 0)
                return 1;
            else if(n == 1)
                return 10;
            int res = 10;
            int range = pow(10.0, n);
            for(int i=10; i<range; ++i) {
                int tmp = i, single, flag = 1;
                vector<int> save;
                while(tmp) {
                    single = tmp % 10;
                    if(!save.empty()) {
                        for(auto &it :save) {
                            if(it == single) {
                                flag = 0;
                                break;
                            }
                        }
                    }
                    save.push_back(single);
                    tmp /= 10;
                }
                if(flag)
                    ++res;
            }
            return res;
        }
};
