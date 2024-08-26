#define ll long long
class Solution {
public:
    int dp[101][101] = {};
    int dfs(vector<int>& h, vector<vector<int>> &costs, int i, int k) {
        if (i >= h.size() || k <= 0)
            return i == h.size() && k == 0 ? 0 : 10000000;
        if (!dp[i][k]) {
            dp[i][k] = 10000000;
            for (auto j = i; j <= h.size() - k; ++j)
                dp[i][k] = min(dp[i][k], costs[i][j] + dfs(h, costs, j + 1, k - 1));
        }
        return dp[i][k];
    }
    int minDistance(vector<int>& h, int k) {      
        sort(begin(h), end(h));
        vector<vector<int>> costs(h.size(), vector<int>(h.size()));
        for (auto i = 0; i < h.size(); ++i) {
            for (auto j = i; j < h.size(); ++j) {
                int mailbox = h[(i + j) / 2];
                for (auto p = i; p <= j; ++p)
                    costs[i][j] += abs(mailbox - h[p]);
            }
        }
        return dfs(h, costs, 0, k);
    }
};