#define ll long long
ll M=1e9+7;
class Solution {
public:
    int dp[41][1<<10];

    int func(int ind,int mask,vector<ll> &a){
        int n=a.size();
        if(ind>=40) return mask==(1<<n)-1;
        if(dp[ind][mask]!=-1) return dp[ind][mask];

        int ans=func(ind+1,mask,a);
        for(int i=0; i<n; i++){
            if(!(mask&(1<<i)) && (a[i]&(1ll<<ind))){
                ans=(ans+func(ind+1,mask|(1<<i),a))%M;
            }
        }

        return dp[ind][mask]=ans;
    }

    int numberWays(vector<vector<int>>& a) {
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        vector<ll> choice(n,0);
        for(int i=0; i<n; i++){
            for(auto f:a[i]) choice[i]|=(1ll<<(f-1));
        }
        return func(0,0,choice);
    }
};