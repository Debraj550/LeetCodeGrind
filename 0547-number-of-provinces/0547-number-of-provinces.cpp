class Solution {
public:
    void dfs(int node, vector<vector<int>> &adjList, vector<int> &visited) {
	if(visited[node]) return;
	visited[node] = 1;
	for(int adjNode: adjList[node]) {
	if(!visited[adjNode])
		dfs(adjNode, adjList, visited);
}
}

 int findCircleNum(vector<vector<int>>& isConnected) {
  	int v = isConnected.size();
vector<vector<int>> adjList(v);

for(int i = 0; i < isConnected.size(); i++) {
	for(int j = 0; j < isConnected.size(); j++) {
	if(isConnected[i][j] == 1 && i != j) {
	adjList[i].push_back(j);
	adjList[j].push_back(i);
}
}
}


vector<int> visited(v, 0);
int res = 0;

for(int i = 0; i < v; i++) {
	if(!visited[i])  {
dfs(i, adjList, visited);
res++;
}
}

return res;   
  }

};