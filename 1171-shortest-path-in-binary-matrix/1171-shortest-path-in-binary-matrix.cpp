class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)return -1;
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>q;
        q.push({1,{0,0}});
        dis[0][0]=1;
        while(!q.empty())
        {
            int dist=q.top().first;
            int row=q.top().second.first;
            int col=q.top().second.second;
            q.pop();
            int delrow[]={-1,1,0,0,-1,1,1,-1};
            int delcol[]={0,0,-1,1,-1,1,-1,1};
            for(int i=0;i<8;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<n && ncol<n && ncol>=0 && dis[nrow][ncol]>dist+1 
                 &&   grid[nrow][ncol]==0)
                {
                    q.push({1+dist,{nrow,ncol}});
                    dis[nrow][ncol]=1+dist;
                }
            }
        }
        if(dis[n-1][n-1]==1e9)return -1;
        else return dis[n-1][n-1];
        
    }
};