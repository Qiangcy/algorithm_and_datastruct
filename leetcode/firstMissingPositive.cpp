class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int n = nums.size(), res = 0;
      if(n == 0)
          return 1;

      for(int i=0; i<n; ++i) {
          while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]) {
                swap(nums[nums[i]-1], nums[i]);
          }
      }

      for(int i=1; i<=n; ++i) {
          if(nums[i-1] != i) {
              return i;
          }
      }
      return n+1;
    }
};
// best: O(n+(n-1)) O(n)
// worst: ;


int find_minmium_n ature_num(vector<int> &numbers)
{
      int n = numbers.size(), res = 0;
      if(n == 0)
          return -1;

      for(int i=0; i<n; ++i) {
          while(a[i]>0 && a[i]<=n && a[i]!=i+1) {
                swap(a[a[i]-1], a[i]);
              //a[a[i]-1] = a[i];//i=1, a[3] = a[1] = 4
          }
      }

      // [2, 2, 4, 9]     1!=2 1
      //int i = 1;
      for(int i=1; i<=n; ++i) {
          if(a[i-1] != i) {
              return i;
          }
      }
      return n+1;
}
