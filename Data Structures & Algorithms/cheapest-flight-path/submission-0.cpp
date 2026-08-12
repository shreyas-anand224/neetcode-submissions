class Solution {
public:
typedef pair<int,pair<int,int>> pii;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto flight : flights)
        {
            int u=flight[0];
            int v=flight[1];
            int w=flight[2];

            adj[u].push_back({v,w});
        }

        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));

        dist[src][0]=0;

        priority_queue<pii,vector<pii>,greater<pii>> pq;

        pq.push({0,{src,0}}); //{cost,{node,flights}};

        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();

            int d=top.first;
            int u=top.second.first;
            int edges=top.second.second;

            if(d > dist[u][edges])
                continue;
            
            if(edges==k+1)
                continue;
            

            for(auto [v,w] : adj[u])
            {
                if(dist[v][edges+1] > dist[u][edges] + w)
                {
                    dist[v][edges+1] = dist[u][edges] + w;
                    pq.push({dist[v][edges+1],{v,edges+1}});
                }
            }
        }


       int ans=INT_MAX;

        for(int i=0;i<=k+1;i++)
            ans=min(ans,dist[dst][i]); //can reach using any number of edges

        return ans==INT_MAX ? -1 : ans;




    }
};
