class Solution {
public:
    int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
   

    // Base case: If we have considered all elements and the target is still not 0, return 0
    if (ind == 0)
    {
        if(target==0 && arr[0]==0)return 2;
        if(target==0 ||arr[0]==target) return 1;
        return 0;
    }

    // If the result for this state is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Recursive cases
    // 1. Exclude the current element
    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    // 2. Include the current element if it doesn't exceed the target
    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the DP table and return
    return dp[ind][target] = notTaken + taken;
}
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
       return findWaysUtil(n - 1,target,arr, dp);
        // code here
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalsum=0;
        for(auto &it : nums) totalsum+=it;
        if(totalsum-target<0 || (totalsum-target)%2)return false;
        
        return perfectSum(nums,(totalsum-target)/2); 
    }
};