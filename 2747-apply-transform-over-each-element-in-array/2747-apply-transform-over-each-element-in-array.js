/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const resArr = arr.map((val, idx) => fn(val, idx));
    return resArr;
};