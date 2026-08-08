class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int total=0;
        
        for(auto x : nums)
            total+=x;

        if(total%2!=0)
            return false;
        
        int target=total/2;

        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));

        for(int i=0;i<=n;i++)
            dp[i][0]=true;//can make sum=0 with any no of elements here even 0 elements count
        
        for(int i=1;i<=n;i++)
        {
            for(int sum=0;sum<=target;sum++)
            {
                bool nottake=dp[i-1][sum];
                bool take=false;
                
                if(nums[i-1]<=sum)
                    take=dp[i-1][sum-nums[i-1]];
                
                dp[i][sum]=take || nottake;
            }
        }
        return dp[n][target];


        //dp[i][j]= can you make the sum with the first i elements here, i is not an index but no of elements
    }
};
