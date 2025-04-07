class Solution {
public:
    int helper(vector<int>& prices, int n, int i,int buy,int cap,vector<vector<vector<int>>> &dp)
    {
        if(i==n || cap==0)return 0;
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        int profit;

        if(buy==0)
        {
            profit=max(0+helper(prices,n,i+1,0,cap,dp),-prices[i]+
            helper(prices,n,i+1,1,cap,dp));
        }
        if(buy==1)
        {
            profit=max(0+helper(prices,n,i+1,1,cap,dp),prices[i]+
            helper(prices,n,i+1,0,cap-1,dp));
        }

        return dp[i][buy][cap]=profit;

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(prices,n,0,0,2,dp);
    }
};