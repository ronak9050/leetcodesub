class Solution {
public:
    int func(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e6;
        for(int p=i; p<j; p++){
            ans=min(ans,(s[i]!=s[j])+func(i,p,s,dp)+func(p+1,j,s,dp));
        }
        return dp[i][j]=ans;
    }

    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return func(0,n-1,s,dp)+1;
    }
};