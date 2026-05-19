/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if (digits.length === 0) return [];
    let alphas = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
    let result = [];

    function generateCombinations(index, current) {
        if (index === digits.length) {
            result.push(current);
            return;
        }

        let letters = alphas[digits[index]];

        for (let ch of letters) {
            generateCombinations(index + 1, current + ch);
        }
    }

    generateCombinations(0, "");

    return result;
};