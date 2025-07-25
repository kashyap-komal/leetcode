class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        grid[i][j]=0;
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1)
            dfs(grid,nrow,ncol);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1)
                dfs(grid,i,j);
            }
        }
         return accumulate(begin(grid), end(grid), 0, [](int sum, auto row) { return sum + accumulate(begin(row), end(row), 0); });
        
    }
};