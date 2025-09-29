class Solution {
public:
    int solve(vector<int>& values,int i,int j, vector<vector<int>>&dp)
    {
        if(j-i<2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int res=INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            int cost =values[i]*values[k]*values[j]+
            solve(values,i,k,dp)+
            solve(values,k,j,dp);
            res=min(res,cost);
        }
        return dp[i][j]=res;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n= values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(values,0,n-1,dp);

        // int n = values.size();
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // for (int i = n - 1; i >= 0; --i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         for (int k = i + 1; k < j; ++k) {
        //             dp[i][j] = min(dp[i][j] == 0 ? INT_MAX : dp[i][j],
        //                 dp[i][k] + values[i] * values[k] * values[j] + dp[k][j]);
        //         }
        //     }
        // }
        // return dp[0][n - 1];
    }
};