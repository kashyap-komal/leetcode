class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        long long start=0,end=0;
        long long sum=0, res=0;
        for(end=0;end<n;end++)
        {
            sum+=nums[end];
            while((end-start+1)*nums[end]-sum>k)
            {
                sum-=nums[start];
                start++;
            }
            res=max(res,end-start+1);
        }
        return res;

    }
};