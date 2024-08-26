class Solution {
public:
    int func(int i,int j,int t,vector<int>&a,vector<vector<vector<int>>>&dp){
        if(i>j) return 0;
        if(dp[i][j][t]!=-1) return dp[i][j][t];
        int ans;
        if(t){
            ans=max(a[i]+func(i+1,j,1-t,a,dp),a[j]+func(i,j-1,1-t,a,dp));
        }
        else{
            ans=min(-a[i]+func(i+1,j,1-t,a,dp),-a[j]+func(i,j-1,1-t,a,dp));
        }
        return dp[i][j][t]=ans;
    }
    bool predictTheWinner(vector<int>& a) {
        int n=a.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int ans=func(0,n-1,1,a,dp);
        if(ans>=0) return 1;
        return 0;
    }
};