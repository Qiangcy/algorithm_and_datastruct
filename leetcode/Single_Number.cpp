class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto &it : nums)
            res ^= it;
        return res;
    }
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = accumulate(begin(nums), end(nums), 0, bit_xor<int>());
        /* for(auto it : nums) */
        /*     res ^= it; */
        res &= -res;

        vector<int> appear_once(2, 0);
        for(auto it : nums) {
            if((it & res) == 0)
                appear_once[0] ^= it;
            else
                appear_once[1] ^= it;
        }
        return appear_once;
    }
};

public int singleNumber(int[] A) {
    int ones = 0, twos = 0;
    for(int i = 0; i < A.length; i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;
}

int singleNumber(int* nums, int numsSize) {
    // idea : iterate over all elements in array for every bit, get sum of all 1s,
    // bits with sum not multiple of 3, are 1's bit in the single occurance element
    // e.g. , 5,5,5,2 - 101 101 101 010 - 313 - answer is 3%3,1%3,3%3 - 010

    int x, res = 0;

    for(int i = 0; i < sizeof(int)*8; i++){
        x = 1 << i;
        int sum = 0;
        for(int j = 0; j < numsSize; j++){
            if(x & nums[j]) sum++;
        }

        if(sum % 3) res = res | x;
    }

    return res;
}


class Solution {
    // idea : iterate over all elements in array for every bit, get sum of all 1s,
    // bits with sum not multiple of 3, are 1's bit in the single occurance element
    // e.g. , 5,5,5,2 - 101 101 101 010 - 313 - answer is 3%3,1%3,3%3 - 010
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size () == 0)
            return 0;
        int res = 0, sum;
        for(int i=0; i<sizeof(int)*8; ++i) {
            sum = 0;
            for(auto it : nums) {
                if((it>>i) & 1)
                    sum++;
            }
            int x = 1<<i;
            if(sum % 3)
                res |= x;
        }
        return res;
    }
};
