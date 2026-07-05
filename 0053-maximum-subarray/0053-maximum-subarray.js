/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let res = nums[0];
    let maxSoFar = nums[0];

    for(let i = 1; i < nums.length; i++) {
        maxSoFar = Math.max(maxSoFar + nums[i], nums[i]);
        res = Math.max(maxSoFar, res);
    }
    return res;
};