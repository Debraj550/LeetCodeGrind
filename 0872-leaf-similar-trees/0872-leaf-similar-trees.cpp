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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       stack<TreeNode *> q1, q2;
       if(!root1 && root2 || root1 && !root2) return false;
       vector<int> res1,res2;
       q1.push(root1);
        while(!q1.empty()){
            TreeNode *temp = q1.top();
            q1.pop();
            if(!temp->left && !temp->right) res1.push_back(temp->val);
            if(temp->left) q1.push(temp->left);
            if(temp->right) q1.push(temp->right);
        }

        q2.push(root2);
        while(!q2.empty()){
            TreeNode *temp = q2.top();
            q2.pop();
            if(!temp->left && !temp->right) res2.push_back(temp->val);
            if(temp->left) q2.push(temp->left);
            if(temp->right) q2.push(temp->right);
        }

        if(res1.size() == res2.size()) {
            for(int i = 0; i < res1.size(); i++) {
                if(res1[i] != res2[i]) 
                    return false;
            }
            return true;
        }
        return false;
    }
};