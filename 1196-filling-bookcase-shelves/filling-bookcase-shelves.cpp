class Solution {
public:
    int func(int ind,int lvl,int w,vector<vector<int>>&a,vector<vector<int>>&dp){
        int n=a.size();
        if(ind>=n) return 0;
        if(dp[ind][lvl]!=-1) return dp[ind][lvl];
        int curw=w-a[ind][0],mxht=a[ind][1];
        int ans=mxht+func(ind+1,lvl+1,w,a,dp);
        for(int i=ind+1; i<n; i++){
            if(a[i][0]<=curw){
                curw-=a[i][0];
                mxht=max(mxht,a[i][1]);
                ans=min(ans,mxht+func(i+1,lvl+1,w,a,dp));
            }
            else break;
        }
        return dp[ind][lvl]=ans;
    }
    int minHeightShelves(vector<vector<int>>& a, int w) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return func(0,0,w,a,dp);
    }
};