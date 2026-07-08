/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let l = 0;
    let r = 0;
    let longest = 0;
    let charMap = {};
    while(r < s.length) {
        let char = s[r];
        while(charMap[char] === true) {
            charMap[s[l]] = false;
            l++;
        }
        charMap[char] = true;
        longest = Math.max(longest, r - l + 1);
        r++;
    }
    return longest;
};