class Solution {
public:

    int helper(int i,int buy,vector<int>& prices,int n,vector<vector<int>> &dp)
    {
        if(i==n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];

        int profit=0;
        if(buy==0)
        {
            profit= max(0+helper(i+1,0,prices,n,dp),-prices[i]+
            helper(i+1,1,prices,n,dp));
        }
        if(buy==1)
        {
            profit=max(0+helper(i+1,1,prices,n,dp),prices[i]+
            helper(i+1,0,prices,n,dp));
        }
        return dp[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
        {
              return 0;
        }
      
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,0,prices,n,dp);
        
    }
};