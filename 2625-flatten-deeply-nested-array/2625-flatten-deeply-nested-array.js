/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    let x = 0;
    let res = [];
    const flattening = (nums, l) => {
        for(const num of nums) {
            if(Array.isArray(num) && l > 0) 
                flattening(num, l - 1);
            else res.push(num);
        }
    }
    flattening(arr, n);
    return res;
};