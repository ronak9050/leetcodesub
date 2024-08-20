class Solution {
public:
    int func(int i,int j,int k,vector<int>&a,vector<vector<vector<int>>>&dp){
        if(i>j) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=0;
        if(k){
            ans=max(ans,a[i]+func(i+1,j,1-k,a,dp));
            ans=max(ans,a[j]+func(i,j-1,1-k,a,dp));
        }
        else{
            ans=INT_MAX;
            ans=min(ans,a[i]+func(i+1,j,1-k,a,dp));
            ans=min(ans,a[j]+func(i,j-1,1-k,a,dp));
        }
        return dp[i][j][k]=ans;
    }

    bool stoneGame(vector<int>& a) {
        int n=a.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int sum=accumulate(a.begin(),a.end(),0);
        int alc=func(0,n-1,1,a,dp);
        return (alc>sum-alc);
    }
};