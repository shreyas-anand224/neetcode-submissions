class Solution {
public:

    vector<int> dp;

    int solve(int target)
    {

        if(target==1)//when we have nothing left, we cannot obtain any product from it
            return 1;

        int ans=INT_MIN;

        if(dp[target]!=INT_MIN)
            return dp[target];
        
        for(int i=1;i<=target-1;i++)
        {
           int tbreak=solve(target-i) *(i);
           int notbreak=i * (target-i);
          

           ans=max({tbreak,notbreak,ans});
        }

        return dp[target] = ans;


    }
    int integerBreak(int n) {

        dp.resize(n+1,INT_MIN); 
        return solve(n);
    



        //dp[target][k] = max product than we can make from this target such that atleast it needs to be split into atleast k positive numbers
    }
};