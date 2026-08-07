class Solution {
public:
    bool dfs(int node, int target , vector<vector<int>> & adj, vector<bool> & visited)
    {
        visited[node]=true;
        if(node==target)
            return true;

        for(int x : adj[node])
        {       
            if(!visited[x] && dfs(x,target,adj,visited)) //only explore not visited neighbors
                return true;
            else if(visited[x])
                continue;
        }

        return false;
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        int n=numCourses;
        vector<vector<int>> adj(n);

        vector<bool> ans;

        for(auto edge : prerequisites)
        {
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
        }
         vector<bool> visited(n,false);
        for(auto query : queries)
        {
            for(int i=0;i<n;i++)
                visited[i]=false;

            int u=query[0];
            int v=query[1];

            if(dfs(u,v,adj,visited))
                ans.push_back(true);
            
            else
                ans.push_back(false);

        }
        return ans;

    }
};