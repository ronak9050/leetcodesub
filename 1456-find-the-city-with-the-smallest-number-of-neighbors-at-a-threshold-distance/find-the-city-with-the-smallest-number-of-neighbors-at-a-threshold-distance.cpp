class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        for(auto &e:edges){
            dp[e[0]][e[1]]=e[2];
            dp[e[1]][e[0]]=e[2];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
                }
            }
        }
        int ans=1e9,ind=-1;
        for(int i=0; i<n; i++){
            int ct=0;
            for(int j=0; j<n; j++){
                if(i!=j && dp[i][j]<=d) ct++;
            }
            // cout<<i<<" "<<ct<<endl;
            if(ct<=ans){
                ans=ct;
                ind=i;
            }
        }
        return ind;
    }
};