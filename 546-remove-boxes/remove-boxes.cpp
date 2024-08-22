class Solution {
public:

    int func(int i,int j,int ext,vector<vector<int>> &grp, vector<vector<vector<int>>>&dp){
        if(i>=j) return 0;
        if(dp[i][j][ext]!=-1) return dp[i][j][ext];
        int ans=((ext+grp[i][0])*(ext+grp[i][0]))+func(i+1,j,0,grp,dp);
        for(int p=i+2; p<j; p++){
            if(grp[i][1]==grp[p][1]){
                ans=max(ans,func(i+1,p,0,grp,dp)+func(p,j,ext+grp[i][0],grp,dp));
            }
        }
        return dp[i][j][ext]=ans;
    }
    
    int removeBoxes(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> grp;
        int ct=1;
        for(int i=1; i<n; i++){
            if(a[i]==a[i-1]) ct++;
            else{
                grp.push_back({ct,a[i-1]});
                ct=1;
            }
        }
        grp.push_back({ct,a[n-1]});
        vector<vector<vector<int>>> dp(102,vector<vector<int>>(102,vector<int>(102,-1)));
        int ans=func(0,grp.size(),0,grp,dp);
        return ans;
    }
};