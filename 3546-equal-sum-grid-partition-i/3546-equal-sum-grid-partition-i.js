/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var canPartitionGrid = function(grid) {
    let m = grid.length;
    let n = grid[0].length;

    let totalSum = 0;

    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) totalSum += grid[i][j];
    }
    if(totalSum % 2 !== 0) return false;

    let target = totalSum / 2;

    // horizontal cut
    let rowSum = 0;
    for(let i = 0; i < m-1; i++) {
        for(let j = 0; j < n; j++) rowSum += grid[i][j];
        if(rowSum === target) 
            return true;
    }

    // vertical cut
    let colPrefix = 0;
    for (let j = 0; j < n - 1; j++) {
        let colSum = 0;
        for (let i = 0; i < m; i++) {
            colSum += grid[i][j];
        }
        colPrefix += colSum;

        if (colPrefix === target) return true;
    }
    return false;
};


