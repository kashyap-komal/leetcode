class Solution {
public:

   vector<vector<vector<int>>>dp;
   int helper(vector<int> &nums,int i, int k,int op1,int op2)
   {
    if(i>=nums.size())return 0;
     if (op1 < 0 || op2 < 0) return INT_MAX;
    if(dp[i][op1][op2]!=-1)return dp[i][op1][op2];
    int mini=INT_MAX;
    mini=nums[i]+helper(nums,i+1,k,op1,op2);  //no operation performer

    //performing 2nd operation
    if(op2 && nums[i]>=k)
    mini=min(mini, nums[i]-k+helper(nums,i+1,k,op1,op2-1));

    //first opertion perfomed
    if(op1)
    mini=min(mini,(int)ceil(nums[i]/2.0)+helper(nums,i+1,k,op1-1,op2));

    //performed bith operation on same index
    if(op1 && op2 && nums[i]>=k)
    {   //aply op1 first the op2
        int val=nums[i];
        val=ceil(val/2.0);
        if(val>=k)
        mini=min(mini,val-k+helper(nums,i+1,k,op1-1,op2-1));
        //apply op2 first tehn op1
        val=nums[i]-k;
        mini=min(mini,(int)ceil(val/2.0)+helper(nums,i+1,k,op1-1,op2-1));
    }
    return dp[i][op1][op2]=mini;

   }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
       int n=nums.size();
       dp=vector<vector<vector<int>>>(n,vector<vector<int>>(op1+1,
       vector<int>(op2+1,-1) ));
       return helper(nums,0,k,op1,op2); 
    }
};