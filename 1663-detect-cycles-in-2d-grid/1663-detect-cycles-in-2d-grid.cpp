class Solution {
    int row,col;
    vector<pair<int,int>>moves={{1,0},{-1,0},{0,1},{0,-1}};
public:
  bool dfs(int i,int j,auto &grid,char ch, auto &vis,int pi,int pj)
  {
    if(i<0 || i>=row || j<0 ||j>=col)return false;
    if(grid[i][j]!=ch)return false;
   if(vis[i][j]) return true;
   vis[i][j]=true;
    bool ans=false;

    for(auto[movex,movey] : moves)
    {
        movex+=i,movey+=j;
        if(movex!=pi || movey!=pj)
        ans=ans||dfs(movex,movey,grid,ch,vis,i,j);
    }
    return ans;
  }
    bool containsCycle(vector<vector<char>>& grid) {
        row=grid.size();
        col=grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,false));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!vis[i][j])
                {
                    bool iscycle=dfs(i,j,grid,grid[i][j],vis,-1,-1);
                    if(iscycle)return true;
                }
            }
        }
        return false;
    }
};