class Solution {
public:
    int triangularSum(vector<int>& nums) {
         while (nums.size() > 1) {
            vector<int> new_nums;//har iteration ke baad nnums.szie()update ho rha hai to isliye hmloh for loop me nums.size() le rhe hai instead of declaring n= nums.size()at the begining
            for (int i = 0; i < nums.size() - 1; ++i) {
                new_nums.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = move(new_nums);
        }
        return nums[0];
      
        
    }
};