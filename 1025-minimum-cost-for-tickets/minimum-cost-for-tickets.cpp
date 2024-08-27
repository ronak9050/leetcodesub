class Solution {
public:
    int func(int i,int t,vector<int>&a,vector<int>&cost,vector<vector<int>>&dp){
        int n=a.size();
        if(i>=n) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        int ans=INT_MAX,tocal;
        if(t==0) tocal=i+1;
        else if(t==1) tocal=lower_bound(a.begin(),a.end(),a[i]+7)-a.begin();
        else tocal=lower_bound(a.begin(),a.end(),a[i]+30)-a.begin();
        ans=cost[t]+min({func(tocal,0,a,cost,dp),func(tocal,1,a,cost,dp),func(tocal,2,a,cost,dp)});
        return dp[i][t]=ans;
    }

    int mincostTickets(vector<int>& a, vector<int>& costs) {
        sort(a.begin(),a.end());
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return min({func(0,0,a,costs,dp),func(0,1,a,costs,dp),func(0,2,a,costs,dp)});
    }
};