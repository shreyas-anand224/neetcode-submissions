class Solution {
public:

    vector<int> dp;

    int solve(int i, vector<int>& cost)
    {
        // We can start from step 0 or step 1 for free
        if(i==0 || i==1)
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        // Reach step i from either i-1 or i-2
        return dp[i]=min(
            solve(i-1,cost)+cost[i-1],
            solve(i-2,cost)+cost[i-2]
        );
    }

    int minCostClimbingStairs(vector<int>& cost)
    {
        int n=cost.size();

        dp.assign(n+1,-1);

        return solve(n,cost);
    }
};