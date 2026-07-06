/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    if (nums.length === 0) return 0;
    const mp = new Map();
    for(let num of nums) mp.set(num, true);
    let longest = -Infinity;
    for(let [key, val] of mp) {
        if(!mp.has(key-1)) {
            let currStreak = 1;
            let currVal = key
            while(mp.has(currVal+1)) {
                currVal += 1;
                currStreak++;
            }
            longest = Math.max(longest, currStreak);
        }
    }
    return longest;
};