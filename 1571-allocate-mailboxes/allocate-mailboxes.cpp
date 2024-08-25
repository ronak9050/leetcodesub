#define ll long long
class Solution {
public:
    ll func(int i,int j,int k,vector<int>&a,vector<vector<vector<ll>>>&dp){
        if(i>j) return 0;
        if(k==0) return INT_MAX;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        ll ans=INT_MAX,sum=0,ct=0;

        for(int p=i; p<=j; p++){

            sum+=a[p];
            ct++;
            ll cur=0;
            for(int q=i; q<i+ct; q++) {
                cur+=abs(a[q]-a[i+ct/2]);
            }

            ans=min(ans,cur+func(p+1,j,k-1,a,dp));
        }
        return dp[i][j][k]=ans;
    }

    int minDistance(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int n=a.size();
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(k+1,-1)));
        return func(0,n-1,k,a,dp);
    }
};