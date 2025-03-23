class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // int positiveCount = 0, negativeCount = 0;

        // for (int num : nums) {
        //     positiveCount += num > 0;
        //     negativeCount += num < 0;
        // }

        // return max(positiveCount, negativeCount);

        int n=nums.size();
        int pos=0,neg=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            neg++;
            else if(nums[i]>0)
            pos++;

        }
        return max(pos,neg);
    }
};