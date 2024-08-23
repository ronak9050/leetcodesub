class Solution {
public:
    vector<vector<int>> moves={{1,0},{-1,0},{0,-1},{0,1}};
    int func(int i,int j,vector<vector<int>>&a,vector<vector<int>>&dp){
        int n=a.size(),m=a[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1;
        for(auto &e:moves){
            int x=i+e[0],y=j+e[1];
            if(x>=0 && y>=0 && x<n && y<m && a[x][y]>a[i][j]){
                ans=max(ans,1+func(x,y,a,dp));
            }
        }
        return dp[i][j]=ans;
    }

    int longestIncreasingPath(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans=max(ans,func(i,j,a,dp));
            }
        }
        return ans;
    }
};