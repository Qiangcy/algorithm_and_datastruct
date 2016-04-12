class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(nums1.size() > m) {
            nums1.pop_back();
        }
        for(auto &it : nums2) {
            nums1.push_back(it);
        }
        sort(begin(nums1), end(nums1));
    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t=m+n-1;
        if(m > 0)
            m-=1;
        if(n > 0)
            n-=1;
        if(nums2.size()!=0) {
            for(; t>=0; t--) {
                if(n<0)
                    break;
                while(m<0 && n>=0) {
                    nums1[t--] = nums2[n--];
                }
                if(nums1[m] > nums2[n]) {
                    nums1[t] = nums1[m];
                    m--;
                }else {
                    nums1[t] = nums2[n];
                    n--;
                }
            }

        }

    }
};
