/**
 * @param {number[]} nums
 * @return {number}
 */
function solve(idx, currXor, nums) {
    if (idx === nums.length) return currXor;

    let take = solve(idx + 1, currXor ^ nums[idx], nums);
    let notTake = solve(idx + 1, currXor, nums);

    return take + notTake;
}

var subsetXORSum = function(nums) {
    return solve(0, 0 , nums);
};