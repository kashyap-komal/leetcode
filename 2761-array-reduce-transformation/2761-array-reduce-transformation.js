/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let ans=init;
    //we can use forEach,map as well as manual for loop
    nums.map(num=>{
        ans=fn(ans,num)
    })
    // for(let i=0;i<nums.length;i++)
    // {
    //     ans=fn(ans,nums[i]);
    // }
    return ans;
};