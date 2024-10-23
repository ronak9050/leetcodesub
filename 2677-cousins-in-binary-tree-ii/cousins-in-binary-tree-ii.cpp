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
    vector<int> mp;
    void func(TreeNode* r,int d){
        if(r==nullptr) return;
        mp[d]+=r->val;
        func(r->left,d+1);
        func(r->right,d+1);
    }

    void asign(TreeNode* r,int d,int sub){
        if(r==nullptr) return;
        int rval=(r->right? r->right->val:0);
        int lval=(r->left? r->left->val:0);
        r->val=mp[d]-r->val-sub;
        asign(r->left,d+1,rval);
        asign(r->right,d+1,lval);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        mp.resize(100001,0);
        func(root,0);
        asign(root,0,0);
        return root;
    }
};