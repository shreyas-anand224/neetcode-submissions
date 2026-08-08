class Solution {
public:

vector<int> down, up;

    void dfs1(int u, int p , vector<vector<int>> &adj)
    {
            down[u]=0;

            for(auto v : adj[u])//loop doesnt run for the leaves here
            {
                if(v==p)
                    continue;

                dfs1(v,u,adj);

                down[u]  = max(down[u],1+down[v]);
            }
    }

    void dfs2(int u, int p, vector<vector<int>> & adj)
    {
        int best1=-1;
        int best2=-1;
        int bestchild=-1;

        for(auto v  :adj[u])
        {
            if(v==p)
                continue;
           
            if(down[v] > best1)
            {
                best2=best1;
                best1=down[v];
                bestchild=v;
            }

            else if (down[v] > best2)
                best2=down[v];
        }

        for(auto v : adj[u])
        {
            if(v==p)
                continue;
            
            int viaparent= 1 + up[u];

            int viasibling;

            if(v==bestchild)
            {
                if(best2==-1)//ie not initiliased
                    viasibling=1;
                else
                    viasibling = 2  + best2;
            }

            else
            {
                viasibling = best1 +2;
            }

            up[v]=max(viaparent,viasibling);//super imp
            dfs2(v,u,adj);//ensure call is for all children here
        }

    }

    

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);

        vector<int> res;


        if(n==1)
            return {0};


        down.assign(n,0);
        up.assign(n,0);

      

        int mini=INT_MAX;

        for(auto edge : edges)
        {
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

          dfs1(0,-1,adj);
        dfs2(0,-1,adj);

        for(int i=0;i<n;i++)
        {
            int height = max(down[i],up[i]);
            mini= min(mini,height);
        }

        for(int i=0;i<n;i++)
        {
            if(max(down[i],up[i])==mini)
                res.push_back(i);
        }

        return res;
      

    }
};