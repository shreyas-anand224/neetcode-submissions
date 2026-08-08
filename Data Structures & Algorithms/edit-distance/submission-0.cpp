class Solution {
public:

    int n,m;
    vector<vector<int>> dp;

    int solve(int i, int j, string& word1, string &word2)
    {
        if(i==m && j==n)
            return 0;

        else if( i<m && j==n )//ie word1 left but 2 finished
        {
            return dp[i][j]=(m-i);
        }
        else if(i==m && j<n)
        {
            return dp[i][j]=n-j;
        }

        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        
        int ans=INT_MAX;

        if(word1[i]==word2[j])
            return dp[i][j]=solve(i+1,j+1,word1,word2);
        
        int replace= 1+ solve(i+1,j+1,word1,word2);

        int del = 1+solve(i+1,j,word1,word2);

        int insert = 1 + solve(i,j+1,word1,word2);

        ans=min({ans,replace,del,insert});

        return dp[i][j]=ans;
    }

    int minDistance(string word1, string word2) {

        m=word1.size();
        n=word2.size();

        dp.assign(m+1,vector<int>(n+1,INT_MAX));

        return solve(0,0,word1,word2);
        //dp[i][j]=min ops to convert word1 from index i onwards to word2 from index j onwards
    }

};
