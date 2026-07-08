 /**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    intervals.sort((a,b) => a[0] - b[0]);
    const res = [];
    res.push(intervals[0]);
    for(let i = 1; i < intervals.length; i++) {
        const [currStart, currEnd] = intervals[i];
        const [lastStart, lastEnd] = res[res.length-1];

        if(lastEnd >= currStart) {
            res.pop();
            res.push([lastStart, Math.max(currEnd, lastEnd)]);
        }
        else res.push(intervals[i]);
    }
    return res;

};