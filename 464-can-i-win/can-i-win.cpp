class Solution {
public:
    int func(int turn,int mask,int tot,int mx,vector<vector<int>>&dp){
        int sum=0;
        if(dp[turn][mask]!=-1) return dp[turn][mask];
        for(int i=1; i<=mx; i++){
            if((mask>>i)&1) sum+=i;
        }
        if(tot<=sum) return !turn;
        int ans=1-turn;
        for(int i=1; i<=mx; i++){
            if((mask&(1<<i))==0){
                if(turn) ans|=func(1-turn,mask|(1<<i),tot,mx,dp);
                else ans&=func(1-turn,mask|(1<<i),tot,mx,dp);
            }
        }
        return dp[turn][mask]=ans;
    }
    bool canIWin(int mx, int tot) {
        if(mx*(mx+1)/2<tot) return 0;
        if(tot==0) return 1;
        vector<vector<int>> dp(2,vector<int>((1<<(mx+1)),-1));
        return func(1,0,tot,mx,dp);
    }
};