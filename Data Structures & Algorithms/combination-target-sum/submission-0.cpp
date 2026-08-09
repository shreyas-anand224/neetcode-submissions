class Solution {
public:

    int goal;
    vector<vector<int>> ans;

    void solve(int index, int &currsum, vector<int>& curr, vector<int> & nums)
    {
        int n=nums.size();

        if(currsum == goal )
        {
            ans.push_back(curr);
            return ;
        }
        if(currsum>goal)
            return;

        for(int i=index; i<n ;i++)
        {
            currsum+=nums[i];
            curr.push_back(nums[i]);

            solve(i,currsum,curr,nums);//ensures can select same element again

            currsum-=nums[i];

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        int currsum=0;
        goal = target;
        
        vector<int> curr;

        solve(0,currsum,curr,nums);

        return ans;


    }
};
