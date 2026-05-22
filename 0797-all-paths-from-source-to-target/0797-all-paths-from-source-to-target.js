/**
 * @param {number[][]} graph
 * @return {number[][]}
 */
function findPossible(curr, end, graph, temp, res) {
    if(curr === end) {
        res.push([...temp, curr]);
        return;
    }
   
    let canMove = graph[curr];
    for(let i = 0; i < canMove.length; i++) {
        let toNode = canMove[i];
        temp.push(curr);
        findPossible(toNode, end, graph, temp, res);
        temp.pop();
    }
    return;
}
var allPathsSourceTarget = function(graph) {
    let nodes = graph.length;
    let res = [];
    findPossible(0, nodes - 1, graph, [], res);
    return res;
};