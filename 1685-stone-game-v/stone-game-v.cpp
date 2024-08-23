class Solution {
public:
    int func(int i,int j,vector<int>&a,vector<vector<int>>&dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0,sum=a[j]-(i>0? a[i-1]:0);
        for(int p=i; p<=j; p++){
            int cur=a[p]-(i>0? a[i-1]:0);
            if(cur<sum/2) ans=max(ans,cur+func(i,p,a,dp));
            else if(cur==sum/2){
                if(sum%2==0) ans=max({ans,sum/2+func(p+1,j,a,dp),sum/2+func(i,p,a,dp)});
                else ans=max(ans,cur+func(i,p,a,dp));
            }
            else ans=max(ans,sum-cur+func(p+1,j,a,dp));
        }
        return dp[i][j]=ans;
    }

    int stoneGameV(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=1; i<n; i++) a[i]+=a[i-1];
        return func(0,n-1,a,dp);
    }
};