class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),l=0,r=0;
      while(r<n)
      {
        nums[l]=nums[r];
        while(nums[r]==nums[l])
            r++;
        l++;//counts total number of solutions here
      }
      return l;
    }
};