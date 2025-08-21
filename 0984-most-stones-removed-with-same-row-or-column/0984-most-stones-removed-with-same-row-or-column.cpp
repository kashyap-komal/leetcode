class Disjointset{
    public:
    vector<int>parent,size;
    Disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=i;
        }
    }
    int findupar(int node)
    {
        if(node==parent[node])
        return node;

        return parent[node]=findupar(parent[node]);
    }

  void unionbysize(int u,int v)
    {
        int ultimateparent_u=findupar(u);
        int ultimateparent_v=findupar(v);

        if(ultimateparent_u==ultimateparent_v)return ;

        if(size[ultimateparent_u]<size[ultimateparent_v])
        {
            parent[ultimateparent_u]=ultimateparent_v;
            size[ultimateparent_v]+=size[ultimateparent_u];
        }
        else
        {
            parent[ultimateparent_v]=ultimateparent_u;
            size[ultimateparent_u]+=size[ultimateparent_v];
        }
    }

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones)
        {
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        unordered_map<int,int>stonenodes;
        Disjointset ds(maxrow+maxcol+1);
        for(auto it:stones)
        {
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;
            ds.unionbysize(noderow,nodecol);
            stonenodes[noderow]=1;
            stonenodes[nodecol]=1;
        }
        int c=0;
        for(auto it:stonenodes)
        {
            if(ds.findupar(it.first)==it.first)
            c++;
        }
        return n-c;
        
    }
};