class Solution {
public:
    int dp[12][12][1<<12][2];

    int func(int i,int j,int mask,int c,vector<vector<int>>&a){
        int n=a.size(),m=a[0].size();
        if(i>=n){
            if(mask==(1<<m)-1) return 0;
            return 1e6;
        }
        if(j>=m) {
            if(!c) return 1e6;
            return func(i+1,0,mask,0,a);
        }

        if(dp[i][j][mask][c]!=-1) return dp[i][j][mask][c];
        
        int ans=func(i,j+1,mask,c,a);
        ans=min(ans,a[i][j]+func(i,j+1,mask|(1<<j),1,a));

        return dp[i][j][mask][c]=ans;
    }

    int connectTwoGroups(vector<vector<int>>&a) {
        memset(dp,-1,sizeof(dp));
        return func(0,0,0,0,a);   
    }
};