struct node{
    node* next[26];
    int end=0;
};

class trie{
    node* root=new node();
    public:
    void insert(string &s){
        auto cur=root;
        for(auto e:s){
            if(cur->next[e-'a']==nullptr){
                node* tmp=new node();
                cur->next[e-'a']=tmp;
            }
            cur=cur->next[e-'a'];
        }
        cur->end=1;
    }

    int func(int i,int d,string &s,node* root,node* cur,vector<vector<int>>&dp){
        int n=s.size();
        if(i>=n) return d;
        if(dp[i][d]!=-1) return dp[i][d];
        // cout<<i<<" "<<d<<endl;
        int ans=d+1+func(i+1,0,s,root,root,dp);
        if(cur->next[s[i]-'a']!=nullptr) {
            ans=min(ans,func(i+1,d+1,s,root,cur->next[s[i]-'a'],dp));
            if(cur->next[s[i]-'a']->end==1) ans=min(ans,func(i+1,0,s,root,root,dp));
        }
        // cout<<i<<" "<<d<<" "<<ans<<endl;
        return dp[i][d]=ans;
    }

    int exChar(string &s){
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans= func(0,0,s,root,root,dp);
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        trie tr;
        for(auto &e:d) tr.insert(e);
        return tr.exChar(s);
    }
};