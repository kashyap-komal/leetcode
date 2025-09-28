class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>temp;
        int n=nums.size();
        for(int i=0;i<n;i++) //move novn-zero first to temp array
        {
            if(nums[i]!=0)
            temp.push_back(nums[i]);
        }
        int n2=temp.size();
        for(int i=0;i<n2;i++) //copy each element from temp on by oine to aaray nums
        {
            nums[i]=temp[i];
        }
        for(int i=n2;i<n;i++) // now fill with zero 
        {
            nums[i]=0;
        }
      for(int i=0;i<n;i++)
      {
        cout<<nums[i];
      }
    }
};