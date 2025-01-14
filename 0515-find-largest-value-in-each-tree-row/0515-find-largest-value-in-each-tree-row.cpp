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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        if(!root) return res;
        while(!q.empty()) {
            int sz = q.size();
            int maxi = INT_MIN;
            while(sz--) {
                TreeNode *node = q.front();
                maxi = max(node->val, maxi);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);     
            }
            res.push_back(maxi);
        }

        return res;
    }
};