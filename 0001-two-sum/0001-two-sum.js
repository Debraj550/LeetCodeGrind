/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let mp = {};
    for(let i = 0; i < nums.length ; i++) {
        // check if my complement element exists or not
        let rem = target - nums[i];
        // if it exists return indices of both elements
        if(mp.hasOwnProperty(rem)) {
            return [mp[rem], i];
        }
        // if not found, insert my current element into map
        else {
            mp[nums[i]] = i;
        }
    }
    
    return [-1, -1];
};



    



