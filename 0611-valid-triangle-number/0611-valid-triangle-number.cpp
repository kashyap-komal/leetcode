class Solution {
public:
    int triangleNumber(vector<int>& nums) {
       int c=0;
        sort(nums.begin(),nums.end());
        for(int k=2;k<nums.size();k++)
        {
            int i=0,j=k-1;
            while(i<j)
            {
                if(nums[i]+nums[j]>nums[k])
                {
                    c+=j-i;
                    j-=1;
                }
                else
                {
                    i++;
                }
            }
        }
        return c;
        
    }
};