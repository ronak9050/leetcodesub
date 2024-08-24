class Solution {
public:
    int dp[1001][1001] = {};
    int dfs(vector<int>& s, int i, int j, int sum) {
        if (i == j) return 0;
        if(dp[i][j]) return dp[i][j];
        int ans = sum-s[i]-dfs(s,i+1,j,sum-s[i]);
        ans=max(ans,sum-s[j]-dfs(s,i,j-1,sum-s[j]));
        return dp[i][j]=ans;
    }
    int stoneGameVII(vector<int>& s) {
        return dfs(s, 0, s.size() - 1, accumulate(begin(s), end(s), 0));
    }
};