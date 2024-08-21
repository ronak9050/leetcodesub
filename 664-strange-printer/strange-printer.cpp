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
        vector<vector<int>> dp(n,vector<int>(n,1e6));

        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(i==j) dp[i][j]=0;
                for(int p=i; p<j; p++){
                    dp[i][j]=min(dp[i][j],(s[i]!=s[j])+dp[i][p]+dp[p+1][j]);
                }
            }
        }
        return dp[0][n-1]+1;
    }
};