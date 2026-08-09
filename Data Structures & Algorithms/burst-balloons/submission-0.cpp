class Solution {
public:

    vector<vector<int>> dp;

    int solve(int i, int j, vector<int> & nums)
    {
        int n=nums.size();

        if(i==j)
        {
            dp[i][j]=nums[i];

            if(j+1<n)
                dp[i][j]*=nums[j+1];
            if(i-1>=0)
                dp[i][j]*=nums[i-1];
            
            return dp[i][j];

        }
        if(i>j)
            return 0; 

        if(dp[i][j]!=INT_MIN)
            return dp[i][j];

        int ans= INT_MIN;

        for(int k=i;k<=j;k++)
        {
            int temp=nums[k];

            if(j+1<n)
                temp*=nums[j+1];
            if(i-1>=0)
                temp*=nums[i-1];
            ans=max(ans,solve(i,k-1,nums)+solve(k+1,j,nums)+temp);
        }
        return dp[i][j]=ans;
    }

    int maxCoins(vector<int>& nums) {

        int n=nums.size();

        dp.assign(n,vector<int>(n,INT_MIN));

        return solve(0,n-1,nums);

       //dp[i][j] =max coins on bursting balloons between i and j

    }
};
