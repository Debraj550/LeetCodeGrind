/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode *root, int row, int col, map<int, map<int, vector<int>> > &mp) {
        if(!root) return;
        mp[row][col].push_back(root->val);
        solve(root->left, row - 1, col + 1, mp);
        solve(root->right, row + 1, col + 1, mp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        int row = 0, col = 0;
        
        map<int, map<int, vector<int>> > mp;
        
        solve(root, row, col, mp);
        
        for(auto x: mp) {
            vector<int> temp;
            for(auto y: x.second) {
                auto currRow = y.second;
                sort(currRow.begin(), currRow.end());
                for(int i = 0; i < currRow.size(); i++) 
                    temp.push_back(currRow[i]);
            }
            res.push_back(temp);
        }
        return res;
        
        
    }
};