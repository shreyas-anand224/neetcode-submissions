class Solution {
public:
    typedef pair<int,int> pii;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto edge : times)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
        }

        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;

        priority_queue<pii,vector<pii>,greater<pii>> pq;

        pq.push({0,k});

        while(!pq.empty())
        {
            auto top =pq.top();

            int u=top.second;
            int d=top.first;
            pq.pop();

            if(d > dist[u])
                continue;
            
            for(auto [v,w] : adj[u])
            {
                if( d + w < dist[v])
                {
                    dist[v]= d + w;
                    pq.push({dist[v],v});
                }
            }
        }

        int mini=INT_MIN;

       for(int i=1;i<=n;i++)
       {
        mini=max(mini,dist[i]);
       }
        if(mini==INT_MAX)
            return -1;

        return mini;




    }
};
