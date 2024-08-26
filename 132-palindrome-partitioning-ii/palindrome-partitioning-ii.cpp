class Solution {
public:
    int func(int ind,int n,vector<vector<int>>&dp,vector<int>&dp2){
        if(ind>=n) return 0;
        if(dp2[ind]!=-1) return dp2[ind];
        int ans=1e7;
        for(int i=ind; i<n; i++){
            if(dp[ind][i]) ans=min(ans,1+func(i+1,n,dp,dp2));
        }
        return dp2[ind]=ans;
    }

    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(i==j) dp[i][j]=1;
                else if(s[i]==s[j]){
                    if(i+1>j-1 || dp[i+1][j-1]) dp[i][j]=1;
                }
            }
        }
        vector<int> dp2(n,-1);
        return func(0,n,dp,dp2)-1;
    }
};