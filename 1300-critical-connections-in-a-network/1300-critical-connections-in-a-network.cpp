class Solution {
    int timer=1;
public:
     void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj,vector<int> &tin,vector<int> &lowins,vector<vector<int>>&bridge)
     {
        vis[node]=1;
        tin[node]=lowins[node]=timer;
        timer++;
        for(auto it: adj[node])
        {
            if(it==parent)continue;
            if(vis[it]==0)
            {
                dfs(it,node,vis,adj,tin,lowins,bridge);
                lowins[node]=min(lowins[node],lowins[it]);
                if(lowins[it]>tin[node])
                {
                    bridge.push_back({it,node});
                }
            }
            else
            {
                lowins[node]=min(lowins[node],lowins[it]);
            }
        }
     }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            vector<vector<int>> adj(n);
        for(auto it: connections) //make it 2directional graph
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0); //create vis array
          vector<int> tin(n, -1);
        vector<int> lowins(n, -1);//adjacnet node lowinsertion of time
        vector<vector<int>>bridge;
        dfs(0,-1,vis,adj,tin,lowins,bridge);
        return bridge ;
        
    }
};