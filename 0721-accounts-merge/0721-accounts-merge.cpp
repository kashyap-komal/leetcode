class Disjointset{
    public:
    vector<int>parent,size;
    Disjointset(int n)
    {
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
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u== ulp_v)return ;
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

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        Disjointset ds(n+1);
        unordered_map<string,int>emailtonode;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                if(emailtonode.find(mail)==emailtonode.end())
                {
                    emailtonode[mail]=i;
                }
                else
                {
                    ds.unionbysize(i,emailtonode[mail]);
                }
            }
        }

        vector<vector<string>>mergedmail(n);
        for(auto it: emailtonode)
        {
            string mail=it.first;
            int node= ds.findupar(it.second);
            mergedmail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            if(mergedmail[i].size()==0)continue;
            sort(mergedmail[i].begin(),mergedmail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedmail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

return ans;

    }
};