struct node{
    node* next[26];
    int ct=0;
};

class trie{
    node* root=new node();
    public:
    void insert(string &s){
        auto cur=root;
        for(auto e:s){
            if(cur->next[e-'a']==nullptr){
                auto tmp=new node();
                cur->next[e-'a']=tmp;
            }
            cur->ct++;
            cur=cur->next[e-'a'];
        }
        cur->ct++;
    }
    int find(string &s){
        auto cur=root;
        int ans=0;
        for(auto e:s){
            cur=cur->next[e-'a'];
            ans+=cur->ct;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& w) {
        trie tr;
        for(auto &e:w) tr.insert(e);
        vector<int> ans(w.size());
        for(int i=0; i<w.size(); i++){
            ans[i]=tr.find(w[i]);
        }
        return ans;
    }
};