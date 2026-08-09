class Solution {
public:

    vector<vector<int>> dp; /// *X MEANS THAT WE CAN GENERATE 0 OR MORE Xs here, 0 is also an option

    bool solve(int i, int j, string &s, string &p)
    {
        int n=s.size();
        int m=p.size();

        if(i==n && j==m)
            return dp[i][j]=true;
        
        else if(i==n && j<m)//string finished but pattern remains
        {
            if(j+1<m && p[j+1]=='*')//can skip only when * in next place           
                return dp[i][j]=solve(i,j+2,s,p);
            else
                return dp[i][j]=false;
        }
        else if(i<n && j==m)//the pattern finished
            return dp[i][j]=false;

        if(dp[i][j]!=-1)
            return dp[i][j];
if(j + 1 < m && p[j + 1] == '*')
{
    bool skip = solve(i, j + 2, s, p);

    bool take = false;

    if(s[i] == p[j] || p[j] == '.')
        take = solve(i + 1, j, s, p);

    return dp[i][j] = skip || take;
}

        if(s[i] == p[j])//both match
             return dp[i][j]=solve(i+1,j+1,s,p);
        
        else if(p[j]=='.')
           return  dp[i][j]=solve(i+1,j+1,s,p);

        else
            return dp[i][j]=false;
        


    }

    bool isMatch(string s, string p) {

    int n=s.size();
    int m=p.size();

    dp.assign(n+1,vector<int>(m+1,-1));

    return solve(0,0,s,p);
    //dp[i][j]=whether the pattern from i to n in string s matches the pattern from j to m in string p
    }
};
