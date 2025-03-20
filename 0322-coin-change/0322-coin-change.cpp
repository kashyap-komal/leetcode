class Solution {
public:

    int helper(int i, vector<int>& coins, int T, vector<vector<int>>& dp) {
    if(T==0){
        dp[i][T]=0;
        return dp[i][T];
    }
    if(i==0)
    {
        if(T%coins[i]==0)
        {
            return dp[i][T]=T/coins[i];
        }
        else
        return 1e9;
    }
    if (dp[i][T] != -1) return dp[i][T];  // Memoization

    int notake = helper(i - 1, coins, T, dp);  // Don't take current coin
    int take = 1e9;
    if (T >= coins[i]) take = 1 + helper(i, coins, T - coins[i], dp);  // Take current coin

    return dp[i][T] = min(take, notake);  // Minimize coins
}
    int coinChange(vector<int>& coins, int amount) {
   // here in this case greedy is not working as its not optimal for every test case
       int n=coins.size();
       vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int ans= helper(n-1,coins,amount,dp);
       if(ans>=1e9)return -1;
       return ans;
        
    }
};