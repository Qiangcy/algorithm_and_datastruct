/*
For num = 5 you should return [0,1,1,2,1,2].
0, 1, 10, 11, 100, 101
0, 1,  1,  2,   1,   2

O(n)
res
tmp
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0; i<=num; ++i) {
            int tmp_num = i, num_of_one = 0;
            while(tmp_num) {
                if(tmp_num & 1) {
                    num_of_one++;
                }
                tmp_num >>= 1;
            }
            res.push_back(num_of_one);
        }
        return res;
    }
};

/*
`3
res[0,1, ]
0:
1: 1&1==1, 1,
2: 10 &1=0, 1&1=1, 1
*/
