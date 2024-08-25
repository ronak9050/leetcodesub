class Solution {
public:
    int func(int ind,int i,vector<int>&a,vector<int> &mul,vector<vector<int>>&dp){
        int m=mul.size(),n=a.size();
        if(ind>=m) return 0;
        if(dp[ind][i]!=-1) return dp[ind][i];

        int ans=max(mul[ind]*a[n-1-(ind-i)]+func(ind+1,i,a,mul,dp),mul[ind]*a[i]+func(ind+1,i+1,a,mul,dp));

        return dp[ind][i]=ans;
    }
    int maximumScore(vector<int>& a, vector<int>& mul) {
        int n=a.size();
        vector<vector<int>> dp(mul.size(),vector<int>(n,-1));
        return func(0,0,a,mul,dp);
    }
};