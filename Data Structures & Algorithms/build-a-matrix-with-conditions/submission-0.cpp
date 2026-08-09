class Solution {
public:

    vector<int> topsort(unordered_map<int,vector<int>> & adj,int k)
    {
        int n=adj.size();//doesnt necessarily mean all 1 to k
        unordered_map<int,int> indegree;
        vector<int> res;
        queue<int> q;
        int count=0;

        for(auto x : adj)
        {
            for(auto ele : x.second)
                indegree[ele]++;
        }

        for(int i=1;i<=k;i++)
        {
            if(indegree[i]==0)
                q.push(i);//this covers all vertices here as we need to push ALL 1 TO K VERTICES
        }

        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            res.push_back(u);
            count++;//increased when element pops here
            
            for(auto v :  adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        if(count!=k)//ie all vertices not just the size of adj
            return {};
        
        return res;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>> matrix (k,vector<int>(k,0));
        unordered_map<int,vector<int>> row;
        unordered_map<int,vector<int>> col;

        for(auto edge : rowConditions)
        {
            int u=edge[0];
            int v=edge[1];

            row[u].push_back(v);
        }

        for(auto edge : colConditions)
        {
            int u=edge[0];
            int v=edge[1];

            col[u].push_back(v);
        }

        vector<int> toprow =topsort(row,k);
        vector<int> topcol = topsort(col,k);
        if(toprow.size()==0 || topcol.size()==0)
            return {};//RETURN EMPTY MATRIX NOT MATRIX WITH 0s

        unordered_map<int,pair<int,int>> coordinates;

        for(int i=0;i<toprow.size();i++)
        {
            int num=toprow[i];
            coordinates[num].first=i;
        }

        for(int i=0;i<topcol.size();i++)
        {
            int num=topcol[i];
            coordinates[num].second=i;
        }
        //coordinates[num] already points to the map here

        for(auto x : coordinates)
        {
            int val=x.first;
            int r=x.second.first;
            int c=x.second.second;

            matrix[r][c]=val;
        }

        return matrix;







    }
};