class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        //first we are putting exah elemtn in hashset then tale the size of size of set ina variable and then again iterate over the set and put all elements from set to array from starting postion
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int k=s.size();
        int j=0;
        for(auto x:s)
        {
            nums[j++]=x;
        }
        return k;
        
    }
};