class Solution {
public:
    int dp[101][1025];
    int func(int i,int mask,vector<vector<int>>&a){
        if(i>100) return 0;
        if(dp[i][mask]!=-1) return dp[i][mask];
        int ans=func(i+1,mask,a),n=a.size();
        for(int j=0; j<n; j++){
            if(mask&(1<<j)) continue;
            if(a[j][i]){
                ans=max(ans,i+func(i+1,mask^(1<<j),a));
            }
        }
        return dp[i][mask]=ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        vector<vector<int>> a(n,vector<int>(101,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<grid[i].size(); j++) a[i][grid[i][j]]=1;
        }
        return func(1,0,a);
    }
};