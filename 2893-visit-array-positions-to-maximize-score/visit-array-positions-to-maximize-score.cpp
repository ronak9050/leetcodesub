#define ll long long

class Solution {
public:
    ll func(int ind,int x,vector<int>&a,vector<int>&nxs,vector<int>&nxd,vector<ll>&dp){
        int n=a.size();
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        ll ans=a[ind];
        ans=max(ans,a[ind]+func(nxs[ind],x,a,nxs,nxd,dp));
        ans=max(ans,a[ind]-x+func(nxd[ind],x,a,nxs,nxd,dp));
        return dp[ind]=ans;
    }

    long long maxScore(vector<int>& a, int x) {
        int n=a.size();
        int sto=n,ste=n;
        if(a[n-1]&1) sto=n-1;
        else ste=n-1;
        vector<int> nxs(n,n),nxd(n,n);
        for(int i=n-2; i>=0; i--){
            if((a[i]+a[i+1])&1) nxd[i]=i+1;
            else nxd[i]=nxd[i+1];

            if(a[i]&1) {
                nxs[i]=sto;
                sto=i;
            }
            else {
                nxs[i]=ste;
                ste=i;
            }
        }
        vector<ll> dp(n,-1);
        ll ans=func(0,x,a,nxs,nxd,dp);

        return ans;
    }
};