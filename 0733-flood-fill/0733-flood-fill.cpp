class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& image,int newcolor,int delrow[],int delcol[],int initialcolor)
    {
        vis[row][col]=newcolor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 &&nrow<n && ncol>=0 && ncol<m &&
             image[nrow][ncol]==initialcolor && vis[nrow][ncol]!=newcolor)
             {
                dfs(nrow,ncol,vis,image,newcolor,delrow,delcol,initialcolor);
             }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialcolor=image[sr][sc];
        vector<vector<int>>vis=image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,vis,image,color,delrow,delcol,initialcolor);
        return vis;
    }
};