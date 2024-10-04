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
    int func1(TreeNode* r,map<TreeNode*,pair<int,int>> &mp1){
        if(r==nullptr) return 0;
        mp1[r]={func1(r->left,mp1),func1(r->right,mp1)};
        return mp1[r].first+mp1[r].second+1;
    }
    int func2(TreeNode* r,map<TreeNode*,pair<int,int>> &mp1){
        if(r==nullptr) return 0;
        mp1[r]={func2(r->left,mp1),func2(r->right,mp1)};
        return mp1[r].first+mp1[r].second+r->val;
    }

    int dfs(TreeNode* r,map<TreeNode*,pair<int,int>> &mp1,map<TreeNode*,pair<int,int>> &mp2){
        if(r==nullptr) return 0;
        int ans=dfs(r->left,mp1,mp2)+dfs(r->right,mp1,mp2);
        return ans+abs(mp1[r].first-mp2[r].first)+abs(mp1[r].second-mp2[r].second);
    }

    int distributeCoins(TreeNode* root) {
        map<TreeNode*,pair<int,int>> mp1,mp2;
        func1(root,mp1);
        func2(root,mp2);
        return dfs(root,mp1,mp2);
    }
};