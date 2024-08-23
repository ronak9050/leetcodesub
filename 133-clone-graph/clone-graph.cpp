/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        Node* cur=new Node(node->val);
        mp[node->val]=cur;
        for(auto &e:node->neighbors){
            if(mp[e->val]) cur->neighbors.push_back(mp[e->val]);
            else cur->neighbors.push_back(cloneGraph(e));
        }
        return cur;
    }
};