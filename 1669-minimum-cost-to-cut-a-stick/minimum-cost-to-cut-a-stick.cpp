#define ll long long
class Solution {
public:
    ll func(int i,int j,vector<int>&a,vector<vector<ll>>&dp){
        if(j-i<=1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        ll ans=1e13;
        for(int p=i+1; p<j; p++){
            ans=min(ans,a[j]-a[i]+func(i,p,a,dp)+func(p,j,a,dp));
        }
        return dp[i][j]=ans;
    }

    int minCost(int n, vector<int>& a) {
        sort(a.begin(),a.end());
        a.insert(a.begin(),0);
        a.push_back(n);
        int sz=a.size();
        vector<vector<ll>> dp(sz,vector<ll>(sz,1e13));

        for(int i=sz-1; i>=0; i--){
            for(int j=i; j<sz; j++){
                if(j-i<=1) dp[i][j]=0;
                for(int k=i+1; k<j; k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[j]-a[i]);
                }
            }
        }
        return dp[0][sz-1];
    }
};