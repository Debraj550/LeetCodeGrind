class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int i = 0, j = 0, cur_d = 0,
            dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res(m, vector<int>(n, -1));
        for (; head != nullptr; head = head->next) {
            res[i][j] = head->val;
            int newi = i + dir[cur_d][0], newj = j + dir[cur_d][1];
            if (min(newi, newj) < 0 || newi >= m || newj >= n ||
                res[newi][newj] != -1)
                cur_d = (cur_d + 1) % 4;
            i += dir[cur_d][0];
            j += dir[cur_d][1];
        }

        return res;
    }
};