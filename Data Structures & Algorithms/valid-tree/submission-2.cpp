class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> & visited)
    {
        int n=adj.size();
        visited[node]=true;

        for(int x : adj[node])
        {
            if(!visited[x])
            {
                if(dfs(x,node,adj,visited))
                    return true;
            }
            else if(x != parent)
                return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(auto  edge : edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int count=0;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,-1,adj,visited))//can start from -1 for all connected components always
                {
                    
                    return false;//ie not a tree
                }
                count++;
            }
            
        }
        for(int i=0;i<n;i++)
            if(!visited[i])
                return false;

        if(count>1)
            return false;//more than 1 connected component

        return true;

        



    }
};
