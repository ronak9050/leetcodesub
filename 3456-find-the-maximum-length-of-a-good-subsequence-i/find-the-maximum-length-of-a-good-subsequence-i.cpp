class Solution {
public:
    int func(int ind,int last,int k,vector<int>&a,vector<vector<vector<int>>>&dp){
        int n=a.size();
        if(ind>n) return 0;
        if(dp[ind][last][k]!=-1) return dp[ind][last][k];
        int ans=0;
        ans=func(ind+1,last,k,a,dp);
        if(last==0 || a[last-1]==a[ind-1]) ans=max(ans,1+func(ind+1,ind,k,a,dp));
        else if(k) ans=max(ans,1+func(ind+1,ind,k-1,a,dp));
        return dp[ind][last][k]=ans;
    }

    int maximumLength(vector<int>& a, int k) {
        int n=a.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return func(1,0,k,a,dp);
    }
};