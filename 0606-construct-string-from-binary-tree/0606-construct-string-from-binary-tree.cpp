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
public:
    void solve(TreeNode *root, string &temp) {
        if(!root) 
            return;
        temp += to_string(root->val);
        
        if(!root->left && !root->right) 
            return;
        
        temp.push_back('('); 
        solve(root->left, temp);
        temp.push_back(')');
        
        if(root->right) {
             temp.push_back('('); 
            solve(root->right, temp);
            temp.push_back(')');
        }

    }   
    
    string tree2str(TreeNode* root) {
        string ans = "";
        solve(root, ans);
        return ans;
    }
};