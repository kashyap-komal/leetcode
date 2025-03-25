class Solution {
public:
  long long helper(int i,int left,int right,int n,  vector<vector<int>>& cost,vector<vector<vector<long long>>> &dp)
  {
    if(i>=n/2)
    return 0;
    if(dp[i][left][right]!=-1)return dp[i][left][right];
    long long mini=LONG_MAX;
    for(int col1=0;col1<3;col1++)
    {
        if(col1!=left)
        {
            for(int col2=0;col2<3;col2++)
            {
                if((col2!=right) && (col1!=col2))
                {
                    long long res=cost[i][col1]+cost[n-1-i][col2]+helper(i+1,col1,col2,n,cost,dp);
                    mini=min(mini,res);
                }
            }
        }
    }
    return dp[i][left][right]=mini;
  }
    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>> (4,vector<long long>(4,-1)));
        return helper(0,3,3,n,cost,dp);

    }
};