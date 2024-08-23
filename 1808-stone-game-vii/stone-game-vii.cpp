class Solution {
public:

    int func(int i,int j,int t,vector<int>&a,vector<vector<vector<int>>>&dp){
        if(i>=j) return 0;
        if(dp[i][j][t]!=-1) return dp[i][j][t];
        int ans;
        if(t){
            ans=max(a[j]-a[i]+func(i+1,j,1-t,a,dp),a[j-1]-(i>0? a[i-1]:0)+func(i,j-1,1-t,a,dp));
        }
        else{
            ans=min(-a[j]+a[i]+func(i+1,j,1-t,a,dp),-a[j-1]+(i>0? a[i-1]:0)+func(i,j-1,1-t,a,dp));
        }
        return dp[i][j][t]=ans;
    }


    int stoneGameVII(vector<int>& a) {
        int n=a.size();
        vector<int> hsh(n,0);
        for(int i=0; i<n; i++){
            if(i) hsh[i]=hsh[i-1];
            hsh[i]+=a[i];
        }
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return func(0,n-1,1,hsh,dp);
    }
};