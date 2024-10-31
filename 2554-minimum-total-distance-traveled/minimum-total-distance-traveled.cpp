#define ll long long
class Solution {
public:
    ll dp[100][100][101];
    ll func(int i,int j,int k,vector<int>&r,vector<vector<int>>&fac){
        if(i==r.size()) return 0;
        if(j==fac.size()) return 1e13;
        if(k==fac[j][1]) return func(i,j+1,0,r,fac);
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        ll ans=func(i,j+1,0,r,fac);
        ans=min(ans,abs(r[i]-fac[j][0])+func(i+1,j,k+1,r,fac));
        return dp[i][j][k]=ans;
    }

    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& fac) {
        memset(dp,-1,sizeof(dp));
        sort(r.begin(),r.end());
        sort(fac.begin(),fac.end());
        return func(0,0,0,r,fac);
    }
};