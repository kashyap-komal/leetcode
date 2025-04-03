class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int mini=prices[0];
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            int currprofit=prices[i]-mini;
            maxprofit=max(maxprofit,currprofit);
            mini=min(mini,prices[i]);
        }
        return maxprofit;
        
    }
};