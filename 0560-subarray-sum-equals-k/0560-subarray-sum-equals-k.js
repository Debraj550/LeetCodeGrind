/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
    let mp = new Map();
    mp.set(0,1);
    let prefSum = 0;
    let count = 0;
    for(let num of nums) {
        prefSum += num;
        if(mp.has(prefSum-k)) 
            count += mp.get(prefSum-k);
        mp.set(prefSum,( mp.get(prefSum) || 0) + 1 );
    }
    return count;
};