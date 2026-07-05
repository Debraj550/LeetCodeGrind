/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    const mp = new Map();
    for(let num of nums) {
        mp.set(num, (mp.get(num) || 0) + 1);
    }

    for(let [key, val] of mp ) {
        if(val === 1) return key;
    }
    return -1;
    
};