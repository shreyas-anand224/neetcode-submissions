class Solution {
public:

    typedef pair<int,int> pii;
    vector<vector<pair<int,int>>> adj;

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        adj.assign(n, vector<pair<int,int>>());

        for(int i=0;i<n;i++)
        {
            int u=points[i][0];
            int v=points[i][1];

            for(int j=0;j<n;j++)
            {
                int u1=points[j][0];
                int v1=points[j][1];

                int w = abs(u-u1) + abs(v-v1);
                if(j==i)
                    continue;
                
                adj[i].push_back({j,w});
            }
        }

        int sum=0;

        priority_queue<pii,vector<pii>,greater<pii>> pq;

        vector<bool> visited(n,false);

        pq.push({0,0});  //{wt,node};

        while(!pq.empty())
        {
            auto [d,u]= pq.top();

            pq.pop();


            if(visited[u])
                continue;
            sum+=d;
            
            visited[u]=true;

            for(auto edge : adj[u])
            {
                int v=edge.first;
                int w=edge.second;

                if(!visited[v])
                {
                    pq.push({w,v});
                }
            }
           
        }
     return sum;


    }
    };

