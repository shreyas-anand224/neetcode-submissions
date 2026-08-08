class Solution {
public:
    vector<vector<int>> dp;

    int row[4]={0,0,-1,1};
    int col[4]={-1,1,0,0};

    int solve(int i, int j,vector<vector<int>>& matrix )
    {
        int m=matrix.size();
        int n=matrix[0].size();

        if(dp[i][j]!=INT_MIN)
            return dp[i][j];
        
        int ans=1;

        for(int k=0;k<4;k++)
        {
            int nr=i+row[k];
            int nc=j+col[k];

            if(nr<m && nr>=0 && nc<n && nc>=0)
            {
                if(matrix[nr][nc] > matrix[i][j])
                    ans=max(ans, 1 + solve(nr,nc,matrix));
            }
        }
        return dp[i][j]=ans;

        
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {


        int m=matrix.size();
        int n=matrix[0].size();

        dp.assign(m,vector<int>(n,INT_MIN));

        int res=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                res=max(res,solve(i,j,matrix));
        }

    return res;
    //dp[i][j]=length longest increasing path that starts at index i and j    
    }
};
