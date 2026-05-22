
var allPathsSourceTarget = function(graph) {
    let res = [];
    let path = [];

    function dfs(node) {
        path.push(node);
        if (node === graph.length - 1) {
            res.push([...path]);
        } else {
            for (let next of graph[node]) {
                dfs(next);
            }
        }
        path.pop();
    }

    dfs(0);
    return res;
};