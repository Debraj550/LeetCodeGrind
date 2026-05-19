/**
 * @param {number[]} nums
 * @return {number}
 */
var subsetXORSum = function(nums) {
    let res = 0;
    function solve(index, currXor) {
        if(index === nums.length) {
            res += currXor;
            return;
        }
        let xor = currXor ^ nums[index];
        solve(index+1, xor);
        solve(index+1, currXor);
    }
    solve(0, 0);
    return res;
};