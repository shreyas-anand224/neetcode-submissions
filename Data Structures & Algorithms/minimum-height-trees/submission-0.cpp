class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);

        vector<int> res;

        for(auto edge : edges)
        {
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int mini=INT_MAX;
        int count=0;

        for(int i=0;i<n;i++)
        {//start bfs from this node

        int src=i;

        queue<int> q;
        vector<bool> visited(n,false);
        visited[src]=true;
        q.push(i);

        int height=-1;

        while(!q.empty())
        {
            int sz=q.size();
            
            while(sz--)
            {
                int u = q.front();
                q.pop();

                for(auto v : adj[u])
                {
                    if(!visited[v])
                    {
                        visited[v]=true;
                        q.push(v);
                    }
                }
            }
            height++;
        }

        if(height < mini)
        {
            mini=height;
            res.clear();
            res.push_back(i);
        }
        
        else if(height == mini)
        {
            count++;
            res.push_back(i);
        }

        }
        return res;

    }
};