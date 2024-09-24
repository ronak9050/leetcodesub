struct node{
    node* next[10];
};

class trie{
    node* root=new node();
    public:
    void insert(string &s){
        auto cur=root;
        for(auto e:s){
            if(cur->next[e-'0']==nullptr){
                node* tmp=new node();
                cur->next[e-'0']=tmp;
            }
            cur=cur->next[e-'0'];
        }
    }
    int search(string &s){
        auto cur=root;
        int ct=0;
        for(auto e:s){
            if(cur->next[e-'0']){
                ct++;
                cur=cur->next[e-'0'];
            }
            else break;
        }
        return ct;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trie tr;
        for(auto e:arr1){
            string tmp=to_string(e);
            tr.insert(tmp);
        }
        int ans=0;
        for(auto e:arr2){
            string tmp=to_string(e);
            ans=max(ans,tr.search(tmp));
        }
        return ans;
    }
};