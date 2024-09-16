#define ll long long
class Solution {
public:
    ll func(int i,int j,vector<int>&a,vector<int>&b,vector<vector<ll>>&dp){
        if(j<0) return 0;
        if(i<0) return -1e11;
        if(dp[i][j]!=-1e18) return dp[i][j];
        ll ans=func(i-1,j,a,b,dp);
        ans=max(ans,b[i]*1ll*a[j]+func(i-1,j-1,a,b,dp));
        return dp[i][j]=ans;
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=b.size();
        vector<vector<ll>> dp(n,vector<ll>(4,-1e18));
        return func(n-1,3,a,b,dp);
    }
};