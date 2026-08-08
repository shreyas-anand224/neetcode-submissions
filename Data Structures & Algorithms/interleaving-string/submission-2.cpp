class Solution {
public:

    int m;
    int n;
    int len;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int k ,string & s1, string &s2, string & s3)
    {
        if(i==m && j==n && k==len)
            return dp[i][j][k]=true;

       else if(i == m && j < n && k < len)//when just 1 out of s1 and s2 finishes, we can still take from the other possibly
        {
            if(s2[j] == s3[k])
             return dp[i][j][k]=solve(i, j+1, k+1, s1, s2, s3);
             return dp[i][j][k]=false;
        }
        else if(i < m && j == n && k < len)
        {
            if(s1[i] == s3[k])
                return dp[i][j][k]=solve(i+1, j, k+1, s1, s2, s3);
            return dp[i][j][k]=false;
        }
        
        else if(i<m && j<n && k==len)
            return dp[i][j][k]=false;
        
        else if(i == m && j == n && k < len)
            return dp[i][j][k]=false;
        
        else if(i < m && j == n && k == len)
            return dp[i][j][k]=false;
        
        else if(i == m && j < n && k == len)
            return dp[i][j][k]=false;

        if(dp[i][j][k]!=-1)
            return dp[i][j][k];        
        
        bool left=false;

        if(s1[i]==s3[k])
            left=solve(i+1,j,k+1,s1,s2,s3);
        
        bool right = false;

        if(s2[j]==s3[k])
            right = solve(i,j+1,k+1,s1,s2,s3);

        bool ans= left || right;

        return dp[i][j][k]=ans;
        
    
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        m=s1.size();
        n=s2.size();
        len=s3.size();

        dp.assign(m+1,vector<vector<int>>(n+1,vector<int>(len+1,-1)));

        if(m==0 && n==0 && len==0)
            return true;

        if(s3.size()!=(n+m))
            return false;
        
        return solve(0,0,0,s1,s2,s3);
    }
};
