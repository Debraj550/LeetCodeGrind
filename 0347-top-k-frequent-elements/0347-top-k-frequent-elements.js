/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    const mp = new Map();
    for(let num of nums)
        mp.set(num, (mp.get(num) || 0) + 1);
    
    const bucket = Array(nums.length + 1).fill().map(() => []);
    for(const [num, count] of mp) {
        bucket[count].push(num);
    }
    const res = [];
    for(let i = bucket.length-1; i >= 0 && res.length < k; i--){
        if(bucket[i].length)
            res.push(...bucket[i]);
    }
    return res.slice(0,k);
};