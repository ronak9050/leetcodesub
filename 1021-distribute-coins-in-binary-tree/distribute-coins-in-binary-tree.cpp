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
class Solution{
public:
    map<TreeNode*,int> ct;
    map<TreeNode*,int> ch;

// counting number of coins and children in given subtree
    pair<int,int> dfs(TreeNode* root){
        if(root==nullptr) return {0,0};
        auto l=dfs(root->left);
        auto r=dfs(root->right);
        ct[root]=root->val+l.first+r.first;
        ch[root]=1+l.second+r.second;
        return {ct[root],ch[root]};
    }

// calculating value for each node --> coin move required from parents (if any)
    int func(TreeNode* root){
        if(root==nullptr) return 0;
        int ans=func(root->left);
        ans+=func(root->right);
        return ans+abs(ct[root]-ch[root]);
    }

    int distributeCoins(TreeNode* root){
        dfs(root);
        return func(root);
    }
};