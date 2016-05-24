class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            auto it = end(digits)-1;
            *it += 1;
            for(; it!=begin(digits); --it) {
                if(*it > 9) {
                    *(it-1) += 1;
                    (*it) %= 10;
                }else {
                    break;
                }
            }
            if(*it > 9) {
                (*it) %= 10;
                digits.insert(it, 1);
            }
            return digits;
        }
};

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            const int n = digits.size();
            for (int i = n - 1; i >= 0; --i) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                }else {
                    digits[i]++;
                    return digits;
                }
            }

            digits.insert(begin(digits), 1);
            return digits;
        }
};
