/**
 * @param {number[]} nums
 * @return {number[]}
 */
var rearrangeArray = function(nums) {
    let res = Array(nums.length).fill(0);
    let pos = 0;
    let neg = 1;
    for(let i = 0; i < nums.length; i++) {
        if(nums[i] < 0) {
            res[neg] = nums[i];
            neg+=2;
        }
        else {
            res[pos] = nums[i];
            pos+=2;
        }
    }
    return res;
};