class Disjointset{
    public:
    vector<int>parent,size;
    Disjointset(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findupar(int node)
    {
        if(node == parent[node])
        return node;
        return parent[node]=findupar(parent[node]);
    }
    void unionbysize(int u,int v)
    {
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

        


    }
      bool connected(int a, int b) {
        return findupar(a) == findupar(b);
    }

};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();
        Disjointset ds(n*n);
        vector<array<int,3>>cells;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cells.push_back({grid[i][j],i,j});
            }
        }
        sort(cells.begin(),cells.end());//sort the array suing elevatio point
        vector<vector<bool>>active(n,vector<bool>(n,false));
         int dr[]={-1,0,1,0};
         int dc[]={0,-1,0,1};

         for(auto cell:cells)
         {
            int elev=cell[0],i=cell[1],j=cell[2];
            active[i][j]=true;
            int  node=i*n+j;
            for(int d=0;d<4;d++)
            {
                int nr=i+dr[d];
                int nc=j+dc[d];
                if(nr>=0 && nr<n && nc>=0 && nc<n && active[nr][nc])
                {
                    int adjnode= nr*n+nc;
                    ds.unionbysize(node,adjnode);
                }
            }
            if(ds.connected(0,n*n-1))
            {
                return elev;
            }
         }
         return -1;



    }
};