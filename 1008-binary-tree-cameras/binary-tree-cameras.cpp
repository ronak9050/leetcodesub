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
    int ct=0;
    unordered_map<TreeNode*,bool> mp;
    void func(TreeNode* r, TreeNode* par){
        if(r==nullptr || (r->left==nullptr && r->right==nullptr) ) return;
        func(r->left,r);
        func(r->right,r);
        if((r->left && mp[r->left]==0) || (r->right && mp[r->right]==0)){
            ct++;
            mp[r]=1;
            if(par) mp[par]=1;
        }
    }

    int minCameraCover(TreeNode* root) {
        func(root,nullptr);
        if(!mp[root]) ct++;
        return ct;
    }
};