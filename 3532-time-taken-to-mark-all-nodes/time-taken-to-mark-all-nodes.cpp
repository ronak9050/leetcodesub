class Solution {
public:
    int dfs(int ind,int par,vector<vector<int>>&g,vector<vector<int>>&dp){
        for(auto &e:g[ind]){
            if(e==par) continue;

            int num=(e%2? 1:2)+dfs(e,ind,g,dp);
            if(num>dp[ind][0]){
                dp[ind][1]=dp[ind][0];
                dp[ind][0]=num;
            }
            else if(num>dp[ind][1]) dp[ind][1]=num;
        }
        return dp[ind][0];
    }

    void dfs2(int ind,int par,int t,vector<vector<int>>&g,vector<vector<int>>&dp,vector<int>&ans){
        ans[ind]=max(dp[ind][0],t);
        int pa=(ind%2? 1:2);
        for(auto &e:g[ind]){
            if(e==par) continue;
            
            int curr=dp[e][0]+(e%2? 1:2);
            int x;
            if(curr==dp[ind][0]) x=dp[ind][1];
            else x=dp[ind][0];
            dfs2(e,ind,max(t+pa,x+pa),g,dp,ans);
        }
    }
    
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> g(n);
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int>> dp(n,vector<int>(2,0));
        vector<int> ans(n,0);
        dfs(0,-1,g,dp);

        dfs2(0,-1,0,g,dp,ans);
        return ans;
    }
};