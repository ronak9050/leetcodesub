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

#define ll long long
class Solution {
public:

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll> pq; 
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int sz=q.size();
            ll cur=0;
            for(int i=0; i<sz; i++){
                auto it=q.front();
                q.pop();
                cur=cur+it->val;
                if(it->right) q.push(it->right);
                if(it->left) q.push(it->left);
            }
            pq.push_back(cur);
        }
        if(pq.size()<k) return -1;
        sort(pq.begin(),pq.end(),greater<ll>());
        return pq[k-1];
    }
};