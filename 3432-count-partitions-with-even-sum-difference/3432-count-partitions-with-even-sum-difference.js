/**
 * @param {number[]} nums
 * @return {number}
 */
var countPartitions = function(nums) {
 const totalsum= nums.reduce((a,b)=>a+b)
 return totalsum%2 === 0 ? nums.length-1 :0 ;
};