class Solution {
public:

     vector<vector<int>> ans;

    void solve(int index , vector<int> &curr, vector<int> &nums)
    {
        int n=nums.size();
        ans.push_back(curr);

        for(int i=index;i<n;i++)
        {

            if(i > index && nums[i]==nums[i-1])
                continue;
            curr.push_back(nums[i]);

            solve(i+1,curr,nums);

            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<int> curr;
        solve(0,curr,nums);

        return ans;
        
    }
};
