class Solution {
public:
    int dfs(int ind,int par,vector<vector<int>>&g,vector<vector<int>>&dp){
        int a1=0,a2=0;
        for(auto &e:g[ind]){
            if(e==par) continue;
            int cur=1+dfs(e,ind,g,dp);
            if(a1<cur){
                a2=a1;
                a1=cur;
            }
            else if(a2<cur) a2=cur;
        }
        dp[ind][0]=a1;
        dp[ind][1]=a2;
        return dp[ind][0];
    }

    void dfs2(int ind,int par,int car,vector<vector<int>>&g,vector<vector<int>>&dp,vector<int>&ans){
        ans[ind]=max(car,dp[ind][0]);
        for(auto &e:g[ind]){
            if(e==par) continue;

            int curr=dp[e][0]+1,x;
            if(curr==dp[ind][0]) x=dp[ind][1];
            else x=dp[ind][0];
            dfs2(e,ind,max(car+1,x+1),g,dp,ans);
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int>> dp(n,vector<int>(2,0));
        vector<int> ans(n);
        dfs(0,-1,g,dp);
        dfs2(0,-1,0,g,dp,ans);


        int mn=*min_element(ans.begin(),ans.end());
        vector<int> ret;
        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
            if(ans[i]==mn) ret.push_back(i);
        }
        return ret;
    }
};