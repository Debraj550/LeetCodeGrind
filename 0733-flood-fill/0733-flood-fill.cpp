class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0},{0,-1}};
void helper(vector<vector<int>> &image, int sr, int sc, int color, int m, int n, int sourceColor) {

	if(sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != sourceColor) return;
	image[sr][sc] = color;
	for(auto dir: dirs) {
	helper(image, sr + dir[0], sc + dir[1], color, m, n, sourceColor);
}
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
int m = image.size();
int n = image[0].size();

int sourceColor = image[sr][sc];
if(sourceColor == color)
return image;

helper(image, sr, sc, color, m, n, sourceColor);
return image;  

  }

};