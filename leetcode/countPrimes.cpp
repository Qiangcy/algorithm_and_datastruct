class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        for(int i=2; i<n; ++i) {
            if(is_prime(i))
                ++res;
        }
        return res;
    }
private:
    bool is_prime(int n) {
        for(int i=2; i*i<=n; ++i) {
            if(n%i == 0)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<int> is_prime(n, 1);
        for(int i=2; i*i<n; ++i) {
            if(!is_prime[i])
                continue;
            res++;
            for(int j=i*i; j<n; j+=i) {
                is_prime[j] = 0;
            }
        }
        return res;
    }
};
