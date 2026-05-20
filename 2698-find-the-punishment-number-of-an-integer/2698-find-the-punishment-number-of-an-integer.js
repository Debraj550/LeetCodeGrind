/**
 * @param {number} n
 * @return {number}
 */
var punishmentNumber = function(n) {
     function canPartition(str, index, target) {
        if(index === str.length) {
            return target === 0;
        }
        let num = 0;
        for(let j = index; j < str.length; j++) {
            num = num * 10 + (str[j] - '0');
            if(num > target) break;
            if(canPartition(str, j + 1, target - num)) {
                return true;
            }
        }

        return false;
    }
    let ans = 0;
    for(let i = 1; i <= n; i++) {
        let square = i * i;
        if(canPartition(square.toString(), 0, i)) {
            ans += square;
        }
    }
    return ans;
};