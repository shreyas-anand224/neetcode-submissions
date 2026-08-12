class Solution {
public:

typedef pair<int,pair<int,int>> pii;
    int swimInWater(vector<vector<int>>& grid) {

        int n=grid.size();

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        dist[0][0]=grid[0][0];

        priority_queue<pii,vector<pii>,greater<pii>> pq;

        pq.push({dist[0][0],{0,0}});

        int row[4]={0,0,-1,1};
        int col[4]={-1,1,0,0};

        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();

            int d=top.first;
            int r=top.second.first;
            int c=top.second.second;

            if(d > dist[r][c])
                continue;
            for(int k=0;k<4;k++)
            {
                int nr=r+row[k];
                int nc=c+col[k];

                if(nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                int maxi=max(d,grid[nr][nc]);

                if(dist[nr][nc] > maxi)
                {
                    dist[nr][nc]=maxi;
                    pq.push({maxi,{nr,nc}});
                }

            }
        }

    return dist[n-1][n-1];

        




    }//dist[r][c]=maximum miminma of the maximum edge encountered reaching this cell here


};
