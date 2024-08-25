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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pre,post,ino;
    stack<pair<TreeNode*,int>> st;
        if(root==nullptr) return post;
    st.push({root,1});
    while(!st.empty()){
        int num=st.top().second;
        TreeNode* temp=st.top().first;
        if(num==1){
            pre.push_back(temp->val);
            st.top().second++;
            if(temp->left!=nullptr) st.push({temp->left,1}); 
        }
        else if(num==2){
            ino.push_back(temp->val);
            st.top().second++;
            if(temp->right!=nullptr) st.push({temp->right,1});
        }
        else{
            post.push_back(temp->val);
            st.pop();
        }
    }
        return post;
    }
};