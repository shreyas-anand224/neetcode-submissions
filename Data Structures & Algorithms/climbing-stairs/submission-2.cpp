class Solution {
public:
    int dfs(int n, vector<int> & memo)
    {
        if(n<=1)
            return 1;
        if(memo[n]!=-1)
            return memo[n];
        return memo[n]=dfs(n-1,memo)+dfs(n-2,memo);
    }
    int climbStairs(int n) {
      vector<int> memo(n+1,-1);//since we have n+1 elements from 0 to n here
      return dfs(n,memo);
    }
};