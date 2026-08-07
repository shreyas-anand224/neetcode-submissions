class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;//skip duplicates here first

            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                int sum=nums[i]+nums[r] +nums[l];
                if(sum>0)
                r--;
                else if(sum<0)
                l++;
                else
                {
                    res.push_back({nums[l],nums[r],nums[i]});
                    l++;r--;
                    while(l<r && nums[l]==nums[l-1])
                    l++;
                }
            }
        }
        return res;
    }
};
