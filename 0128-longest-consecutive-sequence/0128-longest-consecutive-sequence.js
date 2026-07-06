/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    const set = new Set(nums);
    let longest = 0;

    for (let num of set) {
        if (!set.has(num - 1)) {
            let end = num;
            while (set.has(end + 1)) end++;
            longest = Math.max(longest, end - num + 1);
        }
    }

    return longest;
};