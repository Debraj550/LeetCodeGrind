/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const resArr = [];
    for(let i = 0; i < arr.length; i++) {
        resArr.push(fn(arr[i], i));
    }
    return resArr;
};