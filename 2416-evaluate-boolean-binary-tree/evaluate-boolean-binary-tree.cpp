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
    bool dfs(TreeNode* r){
        
        if(r->left){
            if(r->val==3) return dfs(r->left)&&dfs(r->right);
            return dfs(r->left)||dfs(r->right);
        }
        return r->val;
    }
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};