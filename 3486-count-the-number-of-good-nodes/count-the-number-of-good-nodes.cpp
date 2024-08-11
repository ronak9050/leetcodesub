class Solution {
public:
    int ans=0;
    int dfs(int ind,int par,vector<vector<int>>&g,vector<int> &dp){
        int ct=0;
        for(auto &e:g[ind]){
            if(e==par) continue;
            ct+=dfs(e,ind,g,dp);
        }
        set<int> st;
        for(auto &e:g[ind]){
            if(e==par) continue;
            st.insert(dp[e]);
        }
        if(st.size()<2) ans++;
        return dp[ind]=ct+1;
    }
    
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        ans=0;
        vector<vector<int>> g(n);
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> dp(n,0);
        dfs(0,-1,g,dp);
        return ans;
    }
};