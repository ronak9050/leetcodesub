/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool func(TreeNode* r,ListNode* cur,ListNode* h,map<pair<TreeNode*,ListNode*>,bool>&mp){
        if(cur==nullptr) return 1;
        if(r==nullptr) return 0;
        if(mp.find({r,cur})!=mp.end()) return mp[{r,cur}];
        bool ans=0;
        ans|=func(r->left,h,h,mp);
        ans|=func(r->right,h,h,mp);
        if(r->val==h->val){
            ans|=func(r->left,h->next,h,mp);
            ans|=func(r->right,h->next,h,mp);
        }
        if(r->val==cur->val && cur!=h){
            ans|=func(r->left,cur->next,h,mp);
            ans|=func(r->right,cur->next,h,mp);
        }
        return mp[{r,cur}]=ans;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        map<pair<TreeNode*,ListNode*>,bool> mp;
        return func(root,head,head,mp);
    }
};