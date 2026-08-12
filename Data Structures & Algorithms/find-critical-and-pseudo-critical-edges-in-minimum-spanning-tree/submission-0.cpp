class Solution {
public:
    
    vector<int> size,parent;
    
    int v,u,w;

    int find(int node)
    {
        if(node!=parent[node])
            parent[node] = find(parent[node]);
        return parent[node];
    }

    void union_size( int u, int v)
    {
        int rootu=find(u);
        int rootv=find(v);

        if(size[rootu] >= size[rootv])
        {
            parent[rootv]=rootu;
            size[rootu]+=size[rootv];
        }
        else
        {
            parent[rootu]=rootv ;
            size[rootv]+=size[rootu];   
        }
        //each time new dsu will be used here
    }
       


    int getmst(int n, vector<vector<int>> & edges, int skip, int force)
    {
         parent.resize(n);
        size.assign(n,1);

        for(int i=0;i<n;i++)
            parent[i]=i;
        
        int total_weight=0;
        int edge_count=0;

        if(force!=-1)
        {
             u=edges[force][0];
             v=edges[force][1];
             w=edges[force][2];

            union_size(u,v);//intenionally include this edge

            total_weight+=w;
            edge_count++;
        }

        for(int i=0;i<edges.size();i++)
        {
            if(i==skip)
                continue;
            
            if(i==force)
                continue;

             u=edges[i][0];
             v=edges[i][1];
             w=edges[i][2];

            if(find(u) != find(v))
            {
                union_size(u,v);
                total_weight+=w;
                edge_count++;
            }
        }



        if(edge_count!=n-1)
            return INT_MAX;

        return total_weight;

    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
    {
        
        for(int i=0;i<edges.size();i++)
        {
            edges[i].push_back(i);
        }

        sort(edges.begin(),edges.end(),[](vector<int> &a, vector<int> &b)
        {
            return a[2] < b[2];
        });


        int original=getmst(n,edges,-1,-1);


        vector<int> critical,pseudo;

        for(int i=0;i<edges.size();i++)
        {
            int noedge=getmst(n,edges,i,-1);
        

        if(noedge > original)
        {
            critical.push_back(edges[i][3]);
            continue;//since critical so not pseudo critical
        }

        int withedge=getmst(n,edges,-1,i);

        if(withedge==original)
        {
            pseudo.push_back(edges[i][3]);
        }

        }

          return {critical,pseudo};
    }
};