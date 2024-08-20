class Solution {
public:
    int func(int i,int t,vector<int>&a,vector<vector<int>>&dp){
        int n=a.size();
        if(i>=n) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        int ans=INT_MIN;
        if(t){
            ans=max(ans,a[i]+func(i+1,1-t,a,dp));
            if(i+1<n) ans=max(ans,a[i]+a[i+1]+func(i+2,1-t,a,dp));
            if(i+2<n) ans=max(ans,a[i]+a[i+1]+a[i+2]+func(i+3,1-t,a,dp));
        }
        else{
            ans=INT_MAX;
            ans=min(ans,func(i+1,1-t,a,dp));
            if(i+1<n) ans=min(ans,func(i+2,1-t,a,dp));
            if(i+2<n) ans=min(ans,func(i+3,1-t,a,dp));
        }
        return dp[i][t]=ans;
    }
    string stoneGameIII(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int alc=func(0,1,a,dp);
        int sum=accumulate(a.begin(),a.end(),0);
        if(alc>sum-alc) return "Alice";
        else if(alc<sum-alc) return "Bob";
        return "Tie";
    }
};