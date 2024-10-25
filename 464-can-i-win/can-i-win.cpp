class Solution {
public:
    int func(int mask,int tot,int mx,vector<int>&dp){
        if(dp[mask]!=-1) return dp[mask];
        if(tot<=0) return 1;

        int ans=0;
        for(int i=0; i<mx; i++){
            if((mask&(1<<i))==0){
                ans|=func(mask|(1<<i),tot-(i+1),mx,dp);
            }
        }
        return dp[mask]=!ans;
    }

    bool canIWin(int mx, int tot) {
        if(mx*(mx+1)/2<tot) return 0;
        if(tot==0) return 1;
        vector<int> dp((1<<(mx)),-1);
        return !func(0,tot,mx,dp);
    }
};