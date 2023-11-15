/**
 * @param {string} val
 * @return {Object}
 */
class Solution {
    constructor(val) {
        this.val = val;
    }
    toBe(x) {
        if(x === this.val) return true;
        else throw new Error("Not Equal");
    }
    notToBe(x) {
        if(x !== this.val) return true;
        else throw new Error("Equal");
    }
}
var expect = function(val) {
    const x = new Solution(val);
    return x;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */