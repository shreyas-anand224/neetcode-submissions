class Solution {
public:
    double dfs(string u, string target, unordered_map<string,vector<pair<string,double>>>& adj,  unordered_set<string> &visited)
    {
      if( !adj.count(u) || !adj.count(target))
        return -1.00;

        if(u==target)
            return 1.00;
        visited.insert(u);
        

        for(auto x : adj[u])
        {
            string v=x.first;
            double w=x.second;
            if(!visited.count(v))
            {
                double ans=dfs(v,target,adj,visited);
                if(ans!=-1)
                    return ans*w;
            }
        }

        return -1.00;


    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n=equations.size();
       unordered_map<string, vector<pair<string,double>>> adj;
        unordered_set<string> visited;
        vector<double> ans;

        for(int i=0;i<n;i++)
        {
            string u=equations[i][0];
            string v=equations[i][1];
            double val=values[i];

            adj[u].push_back({v,val});
            adj[v].push_back({u,(1/val)});
        }

        for(auto query : queries)
        {

            visited.clear();
            string u=query[0];
            string v=query[1];
            ans.push_back(dfs(u,v,adj,visited));
            

        }
        return ans;
    }
};