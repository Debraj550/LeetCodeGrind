/**
 * @param {number} num
 * @return {number}
 */
var minMaxDifference = function(num) {
    const numstr = num.toString();
    let maxDigit = numstr[0];
    for (let ch of numstr) {
        if (ch !== '9') {
            maxDigit = ch;
            break;
        }
    }
    const max = parseInt(numstr.replaceAll(maxDigit, '9'));
    let minDigit = numstr[0];
    for (let ch of numstr) {
        if (ch !== '0') {
            minDigit = ch;
            break;
        }
    }
    const min = parseInt(numstr.replaceAll(minDigit, '0'));
    return max - min;
};