class Solution {
public:
   bool iscyclic(vector<vector<int>> &adj,vector<int> &vis,int curr)
   {
    if(vis[curr]==2)
     return true;
     vis[curr]=2;
     for(int i=0;i<adj[curr].size();i++)
        if(vis[adj[curr][i]]!=1)
          if(iscyclic(adj,vis,adj[curr][i]))
            return true;

      vis[curr]=1;
      return false;

   }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        vector<int>vis(numCourses,0);
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                if(iscyclic(adj,vis,i))
                return false;
            }
        }
        return true;
        
    }
};