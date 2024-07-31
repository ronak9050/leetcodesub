class Solution {
public:
    int func(int ind,int rem,int w,int ht,vector<vector<int>>&a,vector<vector<int>>&dp){
        int n=a.size();
        if(ind>=n) return ht;
        if(dp[ind][rem]!=-1) return dp[ind][rem];
        int ans=INT_MAX;
        if(a[ind][0]<=rem) ans=func(ind+1,rem-a[ind][0],w,max(ht,a[ind][1]),a,dp);
        ans=min(ans,ht+func(ind+1,w-a[ind][0],w,a[ind][1],a,dp));
        return dp[ind][rem]=ans;
    }
    int minHeightShelves(vector<vector<int>>& a, int w) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(w+1,-1));
        return func(1,w-a[0][0],w,a[0][1],a,dp);
    }
};