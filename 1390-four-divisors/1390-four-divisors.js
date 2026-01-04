/**
 * @param {number[]} nums
 * @return {number}
 */
var sumFourDivisors = function(nums) {
    let ans = 0;

    for(let i = 0; i < nums.length; i++) {
        let div  = 0;
        for(let j = 2; j * j <= nums[i]; j++) {
            if(nums[i] % j === 0) {
                if(div === 0) 
                    div = j;
                else {
                    div = 0;
                    break;
                }
            } 
            else continue;
        } 
        if(div > 0 && div * div < nums[i]) 
            ans += 1 + nums[i] + div + (nums[i] / div);        
    }

    return (ans);
};

