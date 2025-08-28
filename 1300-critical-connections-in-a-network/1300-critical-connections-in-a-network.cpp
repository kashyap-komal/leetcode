class Solution {
    private:
    int timer=1;
public:
void dfs(int node, int parent, vector<int> &vis, vector<int> adj[],int tin[], int lowtin[], vector<vector<int>> &bridges)
{
    vis[node]=1;
    tin[node]=lowtin[node]=timer;
    timer++;
    for(auto it: adj[node])
    {
        if(it == parent )continue;
        if(vis[it]==0)
        {
            dfs(it,node,vis,adj,tin,lowtin,bridges);
            lowtin[node]= min(lowtin[node], lowtin[it]);

            if(lowtin[it]>tin[node])
            {
                bridges.push_back({it,node});
            }
        }
        else
        lowtin[node]= min(lowtin[node], lowtin[it]);
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it: connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int tin[n];
        int lowtin[n];
        vector<vector<int>>bridges;
        dfs(0,-1,vis,adj,tin,lowtin,bridges);
        return bridges;

    }
};