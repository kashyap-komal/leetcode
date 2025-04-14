class Solution {
public:
    int LIS(vector<int> &nums,int n,int indx,int prevind, vector<vector<int>> &dp)
    {
        if(indx==n)
        return 0;
        if(dp[indx][prevind+1]!=-1)
        return dp[indx][prevind+1];

        int nottake= 0+LIS(nums,n,indx+1,prevind,dp);
        int take=0;
        if(prevind==-1 || nums[indx]>nums[prevind])
        {
            take= 1+LIS(nums,n,indx+1,indx,dp);
        }

        return dp[indx][prevind+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return LIS(nums,n,0,-1,dp);
        
    }
};