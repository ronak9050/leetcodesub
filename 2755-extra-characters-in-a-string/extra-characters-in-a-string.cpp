// struct node{
//     node* next[26];
// };

// class trie{
//     node* root=new node();
//     public:
//     void insert(string &s){
//         auto cur=root;
//         for(auto e:s){
//             if(cur->next[e-'a']==nullptr){
//                 node* tmp=new node();
//                 cur->next[e-'a']=tmp;
//             }
//             cur=cur->next[e-'a'];
//         }
//     }

//     int func(int i,int j,string &s,)

//     int exChar(string &s){
//         int n=s.size();
//     }
// };

class Solution {
public:
    int func(int i,int j,string &s,map<string,int>&mp,vector<vector<int>>&dp){
        int n=s.size();
        if(j>=n) return j-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=func(i,j+1,s,mp,dp);
        if(mp.find(s.substr(i,j-i+1))!=mp.end()) ans=min(ans,func(j+1,j+1,s,mp,dp));
        ans=min(ans,j-i+1+func(j+1,j+1,s,mp,dp));
        return dp[i][j]=ans;
    }

    int minExtraChar(string s, vector<string>& d) {
        // trie tr;
        map<string,int> mp;
        for(auto &e:d) mp[e]++;
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return func(0,0,s,mp,dp);
    }
};