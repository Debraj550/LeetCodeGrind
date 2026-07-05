/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let profit = 0;
    let curr = Infinity;
    for(let price of prices) {
        curr = Math.min(price, curr);
        profit = Math.max(price - curr, profit);
    }
    return profit;
}