class Solution {
public:
    int func(int ind,int x,int t,vector<int>&a,vector<vector<vector<int>>>&dp){
        int n=a.size();
        if(ind>=n) return 0;
        if(dp[ind][x][t]!=-1) return dp[ind][x][t];
        int ans=0;
        if(t){
            int sum=0,ct=0;
            for(int i=ind; i<min(n,ind+2*x); i++){
                sum+=a[i];
                ct++;
                ans=max(ans,sum+func(i+1,max(x,ct),1-t,a,dp));
            }
        }
        else{
            ans=INT_MAX;
            int ct=0;
            for(int i=ind; i<min(n,ind+2*x); i++){
                ct++;
                ans=min(ans,func(i+1,max(x,ct),1-t,a,dp));
            }
        }
        return dp[ind][x][t]=ans;
    }

    int stoneGameII(vector<int>& a) {
        int n=a.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2*n+1,vector<int>(2,-1)));
        return func(0,1,1,a,dp);
    }
};