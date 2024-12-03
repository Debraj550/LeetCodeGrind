class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
 int m = mat.size();
int n = mat[0].size();
queue<pair<pair<int,int>, int>> q;   // 1,1 -> 1
vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
vector<vector<int>> res(m, vector<int>(n, 0));
vector<vector<bool>> visited(m, vector<bool>(n, false));

for(int i = 0; i < m; i++) {
	for(int j = 0; j < n; j++) {
	if(mat[i][j] == 0) {
	q.push({ {i,j}, 0 });
		visited[i][j] = true;
}

}
}

while(!q.empty()) {
	auto node = q.front();
	q.pop();
	int x = node.first.first;
	int y = node.first.second;
	int dist = node.second;

	for(auto dir: dirs) {
	int nx = x + dir[0];
	int ny = y + dir[1];
	if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) 
		{
res[nx][ny] = dist + 1;
q.push({{nx,ny}, dist + 1});
visited[nx][ny] = true;
}
}
}

return res;
  
}

};