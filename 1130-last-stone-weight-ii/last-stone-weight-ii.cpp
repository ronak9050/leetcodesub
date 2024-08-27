class Solution {
public:
    int func(int i,int cur,int sum,vector<int>&a,vector<vector<int>> &dp){
        int n=a.size();
        if(i>=n) return abs(cur);
        if(dp[i][sum+cur]!=-1) return dp[i][sum+cur];
        int ans=min(func(i+1,cur-a[i],sum,a,dp),func(i+1,cur+a[i],sum,a,dp));
        return dp[i][sum+cur]=ans;
    }

    int lastStoneWeightII(vector<int>& a) {
        int n=a.size();
        int sum=accumulate(a.begin(),a.end(),0);
        vector<vector<int>> dp(n,vector<int>(2*sum+3,-1));
        return func(0,0,sum,a,dp);
    }
};