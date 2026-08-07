class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> & visited)
    {
        visited[node]=true;
        for(auto it : adj[node])
        {
            if(!visited[it])
                dfs(it,adj,visited);
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans=0;
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i]){
                ans++;
                dfs(i,adj,visited);
                }
        }
        return ans;
    }
};
