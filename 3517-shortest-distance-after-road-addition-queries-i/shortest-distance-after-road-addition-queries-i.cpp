class Solution {
public:
    int dfs(int ind,vector<vector<int>>&g,vector<int>&dp){
        int n=g.size();
        if(ind==n-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=1000;
        for(auto &e:g[ind]){
            ans=min(ans,1+dfs(e,g,dp));
        }
        return dp[ind]=ans;
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        int m=q.size();
        vector<int> ans(m);
        vector<vector<int>> g(n);
        for(int i=0; i<n-1; i++){
            g[i].push_back(i+1);
        }
        for(int i=0; i<m; i++){
            g[q[i][0]].push_back(q[i][1]);
            vector<int> dp(n,-1);
            ans[i]=dfs(0,g,dp);
        }
        return ans;
    }
};
