class Solution {
public:
    bool check(vector<int>& nums) {
        int n= nums.size();
        vector<int>sortednums=nums;
        sort(sortednums.begin(),sortednums.end());
        for(int rotation=0;rotation<n;rotation++)
        {
            bool ismatch=true;
            for(int i=0;i<n;i++)
            {
                if(nums[(rotation+i)%n]!=sortednums[i])
                {
                    ismatch=false;
                    break;
                }
            }
             if (ismatch)
             {
                 return true;
             }
        }
        return false;
        
    }
};