class Solution {
public:
//    void dfs(int row,int col, vector<vector<int>> &vis, vector<vector<char>> &board,
//    int delrow[], int delcol[]){
//     vis[row][col]=1;
//     int n=board.size();
//     int m=board[0].size();
//     for(int i=0;i<4;i++)
//     {
//         int nrow=row+delrow[i];
//         int ncol=col+delcol[i];

//         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
//         board[nrow][ncol] =='0')
//         {
//             dfs(nrow,ncol,vis,board,delrow,delcol);
//         }
//     }

//    }
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>&visited,int i, int j){
        visited[i][j]=true;
        if(i!=0 && grid[i-1][j]=='O' && !visited[i-1][j])dfs(grid,visited,i-1,j);
        if(i!=grid.size()-1 && grid[i+1][j]=='O' && !visited[i+1][j])dfs(grid,visited,i+1,j);
        if(j!=0 && grid[i][j-1]=='O' && !visited[i][j-1])dfs(grid,visited,i,j-1);
        if(j!=grid[0].size()-1 && grid[i][j+1]=='O' && !visited[i][j+1])dfs(grid,visited,i,j+1);
    }
    void solve(vector<vector<char>>& board) {
        // int delrow[] = {-1, 0, +1, 0};
        // int delcol[] = {0, 1, 0, -1}; 
        // int n=board.size();
        // int m=board[0].size();
        // vector<vector<int>> vis(n, vector<int>(m,0));
        // //traverse first and last row
        // for(int j=0;j<m;j++)
        // {
        //     if(!vis[0][j]  && board[0][j]== '0'){
        //         dfs(0,j,vis,board,delrow, delcol);
        //     }
        //     if(!vis[n-1][j] && board[n-1][j] =='0')
        //     {
        //        dfs(n-1,j,vis,board,delrow, delcol); 

        //     }
        // }

        // for(int i=0;i<n;i++)
        // {
        //     if(!vis[i][0] && board[i][0]=='0')
        //     {
        //         dfs(i,0,vis,board,delrow, delcol);
        //     }
        //     if(!vis[i][m-1] && board[i][m-1]=='0')
        //     {
        //         dfs(i,m-1,vis,board,delrow, delcol);
        //     }
        // }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(!vis[i][j] && board[i][j]=='0')
        //         board[i][j]='X';
        //     }
        // }
         vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0; i<board.size();i++){
            if(!visited[i][0] && board[i][0]=='O')dfs(board,visited,i,0);
            if(!visited[i][board[0].size()-1] && board[i][board[0].size()-1]=='O')dfs(board,visited,i,board[0].size()-1);
        }
        for(int j=1; j<board[0].size()-1; j++){
            if(!visited[0][j] && board[0][j]=='O')dfs(board,visited,0,j);
            if(!visited[board.size()-1][j] && board[board.size()-1][j]=='O')dfs(board,visited,board.size()-1,j);
        }
        for(int i=1; i<board.size()-1;i++){
            for(int j=1; j<board[i].size()-1; j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};