/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    const len = nums.length;
    const res = [];
    nums.sort((a,b) => a - b);
    for(let i = 0; i < len - 3; i++) {
        if(i > 0 && nums[i] === nums[i-1]) continue;
        for(let j = i + 1; j < len - 2; j++) {
            if(j > i + 1 && nums[j] === nums[j-1]) continue;
            let left = j + 1;
            let right = len - 1;
            while(left < right) {
                const sum = nums[left] + nums[right] + nums[i] + nums[j];
                if(sum === target) {
                    res.push([nums[i], nums[j], nums[left], nums[right]]);
                    left++;
                    right--;
                    while(left < right && nums[left] === nums[left - 1]) left++;
                    while(left < right && nums[right] === nums[right + 1] ) right--;
                }
                else if(sum < target) left++;
                else right--;
            }
        }
    }

    return res;
};