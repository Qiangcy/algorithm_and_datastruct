class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int vec_size = gas.size();
        for(int start=0; start<vec_size; ++start) {
            int total = 0;
            for(int i=start; i<start+vec_size; ++i) {
                total += gas[i%vec_size] - cost[i%vec_size];
                if(total < 0)
                    break;
            }
            if(total > 0)
                return start;
        }
        return -1;
    }
};
