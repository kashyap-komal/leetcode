class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        int res=0;
        for(int i=0;i<=k;i++)
        {
            res= nums[k-1];
        }
        return res;
        
    }
};