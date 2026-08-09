class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string,vector<string>> adj;

        for(auto edge : tickets)
        {
            string u=edge[0];
            string v=edge[1];

            adj[u].push_back(v);
        }

        for(auto &x : adj)//pass by ref to prevent copy
        {
            sort(x.second.rbegin(),x.second.rend());
        }

        vector<string> currpath;
        currpath.push_back("JFK");

        vector<string> circuit;

        while(currpath.size()>0)
        {
            string currnode=currpath.back();
            if(adj[currnode].size() > 0)//ie the node has some edges left to add to path
            {
                string v = adj[currnode].back();
                adj[currnode].pop_back();
                
                currpath.push_back(v);
            }
            else
            {
                circuit.push_back(currnode);
                currpath.pop_back();
            }
        }
        reverse(circuit.begin(),circuit.end());

        return circuit;





    }
};
