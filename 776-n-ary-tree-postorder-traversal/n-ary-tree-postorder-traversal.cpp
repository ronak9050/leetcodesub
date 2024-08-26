/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void post(Node* r,vector<int>&ans){
        for(auto &e:r->children) post(e,ans);
        ans.push_back(r->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        post(root,ans);
        return ans;
    }
};