#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int res = 1;
        vector<int> flags(2, 0);
        int cnt = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(!nums[i] && cnt<2) {
                flags[cnt++] = i+1;
            }
            res *= nums[i];
        }
        if(flags[0] && !flags[1]) {//only one zero
            res = 1;
            for(int i=0; i<nums.size(); ++i) {
                if(nums[i])
                    res *= nums[i];
                nums[i] = 0;
            }
            nums[flags[0]-1] = res;
        }else {
            for(int i=0; i<nums.size(); ++i) {
                if(!nums[i])
                    nums[i] = 0;
                else
                    nums[i] = res/nums[i];
            }
        }
        return nums;
    }
};

class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> fromBegin(n);
        fromBegin[0]=1;
        vector<int> fromLast(n);
        fromLast[0]=1;

        for(int i=1;i<n;i++){
            fromBegin[i]=fromBegin[i-1]*nums[i-1];
            fromLast[i]=fromLast[i-1]*nums[n-i];
        }
        cout<<"formbegin: ";
        for(auto &it : fromBegin)
            cout<<it<<" ";
        cout<<endl;
        cout<<"fromLast: ";
        for(auto &it : fromLast)
            cout<<it<<" ";
        cout<<endl;

        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]=fromBegin[i]*fromLast[n-1-i];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for(int i=1; i<nums.size(); ++i) {
            res[i] = nums[i-1]*res[i-1];
        }
        int right = 1;
        for(int i=nums.size()-1; i>=0; --i) {
            res[i] *= right;
            right  *= nums[i];
        }
        return res;
    }
};

int main(void) {
    Solution s;
    Solution3 s3;
    vector<int> test = {1, 2, 3, 4, 5};
    vector<int> res  = s3.productExceptSelf(test);
    for(auto it :res)
        cout<<it<<" ";

}
