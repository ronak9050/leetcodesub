#define ll long long

class Solution {
public:
    long long maxPoints(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();

        vector<vector<ll>> dp(n,vector<ll>(m));
        for(int i=0; i<m; i++) dp[0][i]=a[0][i];

        for(int i=1; i<n; i++){
            ll fmx=0,bmx=0;
            for(int j=0; j<m; j++){
                fmx=max(fmx-1,dp[i-1][j]);
                dp[i][j]=fmx+a[i][j];
            }
            for(int j=m-1; j>=0; j--){
                bmx=max(bmx-1,dp[i-1][j]);
                dp[i][j]=max(dp[i][j],bmx+a[i][j]);
            }
        }
        return *max_element(dp[n-1].begin(),dp[n-1].end());
    }
};