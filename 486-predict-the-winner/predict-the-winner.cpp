class Solution {
public:
    int func(int i,int j,vector<int>&a,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=max(a[i]-func(i+1,j,a,dp),a[j]-func(i,j-1,a,dp));
        return dp[i][j]=ans;
    }
    bool predictTheWinner(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=func(0,n-1,a,dp);
        if(ans>=0) return 1;
        return 0;
    }
};