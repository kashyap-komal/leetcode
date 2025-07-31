class Solution {
public:
   bool detect(vector<vector<int>>&adj, vector<int>&vis,int v)
   {
      if(vis[v]==1)
      return true;
      if(vis[v]==2)
      return false;
      vis[v]=1;
      for(int i=0;i<adj[v].size();i++)
       if(detect(adj,vis,adj[v][i]))
       return true;

     vis[v]=2;
     return false;

   }
   bool detectcycle(vector<vector<int>> &adj,int n)
   {
    vector<int>visited(n,0);
    for(int i=0;i<n;i++)
        if(!visited[i])
          if(detect(adj,visited,i))
          return true;
    return false;


    
   }
   void dfs(int node,vector<int>&vis,vector<vector<int>>& adj,stack<int> &myst)
   {
      vis[node]=1;
      for(auto it:adj[node])
      {
        if(!vis[it])
        dfs(it,vis,adj,myst);
      }
      myst.push(node);
      
   }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>res;
        if(detectcycle(adj,numCourses))
        return res;

        stack<int>st;
        vector<int>vis(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            dfs(i,vis,adj,st);
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();

        }
        return res;
    }
};