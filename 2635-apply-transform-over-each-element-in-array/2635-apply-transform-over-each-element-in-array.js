/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let x = arr.map((x, i) => {
        return fn(x, i);
    });
    return x;
};