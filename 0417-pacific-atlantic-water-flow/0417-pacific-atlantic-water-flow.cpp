class Solution {
public:
int m,n;
   void dfs(int r,int c,vector<vector<int>>& heights,vector<vector<bool>>&vis )
   {
    vis[r][c]=true;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nrow=r+drow[i];
        int ncol=c+dcol[i];

        if(nrow<0 || nrow>=m || ncol<0 ||ncol>=n)continue;
        if(vis[nrow][ncol])continue;
        if(heights[nrow][ncol]<heights[r][c])continue;

        dfs(nrow,ncol,heights,vis);
    }
   }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         m=heights.size();
         n=heights[0].size();
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
         vector<vector<bool>>atlantic(m,vector<bool>(n,false));
         for(int i=0;i<m;i++)dfs(i,0,heights,pacific);//first col
         for(int j=0;j<n;j++)dfs(0,j,heights,pacific);//first row
         for(int i=0;i<m;i++)dfs(i,n-1,heights,atlantic);//last col
         for(int j=0;j<n;j++)dfs(m-1,j,heights,atlantic);//last row
         vector<vector<int>>res;
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                res.push_back({i,j});
            }
         }
         return res;
    }
};