class Solution {
    public:
        bool isUgly(int num) {
            while(num) {
                if(num == 1)
                    return true;
                if(num%2 == 0) {
                    num /= 2;
                    continue;
                }else if(num%3 == 0) {
                    num /= 3;
                    continue;
                }else if(num%5 == 0) {
                    num /= 5;
                    continue;
                }else {
                    return false;
                }
            }
            return false;
        }
};

class Solution {
    public:
        bool isUgly(int num) {
            if(num == 0) return false;

            while(num%2 == 0) num/=2;
            while(num%3 == 0) num/=3;
            while(num%5 == 0) num/=5;

            return num == 1;
        }
};

class Solution {
public:
    long long nthUglyNumber(long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> my_priority_queue;
        vector<long long> factor = {2, 3, 5};
        set<long long> my_set;
        my_priority_queue.push(1);
        my_set.insert(1);
        for(long long i=1; ; ++i) {
            long long res = my_priority_queue.top();
            my_priority_queue.pop();
            if(i == n)
                return res;
            for(auto it : factor) {
                long long tmp = it*res;
                if(!my_set.count(tmp)) {
                    my_set.insert(tmp);
                    my_priority_queue.push(tmp);
                }
            }
        }
    }
};
