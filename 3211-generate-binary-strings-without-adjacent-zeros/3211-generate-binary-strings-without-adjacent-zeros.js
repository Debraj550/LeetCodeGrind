/**
 * @param {number} n
 * @return {string[]}
 */
var validStrings = function(n) {
    let res = [];
    function solve(index, curr) {
        if(index === n) {
            res.push(curr);
            return;
        }
        if(curr.length > 0 && curr[curr.length - 1] === '0') solve(index+1, curr + '1');
        else {
            solve(index + 1, curr + '0');
            solve(index + 1, curr + '1');
        }
    }
    solve(0, "");
    return res;
};
