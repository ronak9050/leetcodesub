struct node{
    node* next[26];
    int f=0;
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
            cur=cur->next[e-'a'];
        }
    }

    int func(int ind, string &s,vector<int>&dp){
        int n=s.size();
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=1e6;
        auto cur=root;
        int i=ind;
        while(i<n && cur->next[s[i]-'a']!=nullptr){
            ans=min(ans,1+func(i+1,s,dp));
            cur=cur->next[s[i]-'a'];
            i++;
        }
        return dp[ind]=ans;
    }

    int finder(string &s){
        int n=s.size();
        vector<int> dp(n,-1);
        int ans=func(0,s,dp);
        if(ans>s.size())return -1;
        return ans;
    }
};



class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        trie tr;
        for(auto &e:words){
            tr.insert(e);
        }
        return tr.finder(target);
    }
};