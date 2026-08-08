class Solution {
public:

    vector<unordered_map<int,int>> dp;


    int solve(int i, int target, vector<int> & nums)
    {
        int n=nums.size();
        if(i==n-1)
        {
            if(target==0 && nums[n-1]==0)
                return 2;

            else if(target==nums[i] || target==-nums[i])
                return 1;
            else
                return 0;

        }
        if(dp[i].count(target))
            return dp[i][target];
       
        int left=solve(i+1,target+nums[i],nums);

        
        int right=solve(i+1,target-nums[i],nums);

        return dp[i][target]= left + right;

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n=nums.size();

        

        dp.resize(n);

        return solve(0,target,nums);

    }


    //dp[i][sum]=ways to form the sum with elements from index i onwards'
};
