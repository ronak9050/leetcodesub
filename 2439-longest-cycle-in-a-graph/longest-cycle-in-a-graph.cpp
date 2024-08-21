class Solution {
public:
    vector<int> m;
    vector<vector<int>> adj;
    vector<int> dp;
    int n;

    int dfs(int x, int k) {
        if (dp[x] != -1)
            return dp[x];
        if (m[x] != -1)
            return k - m[x];

        m[x] = k;
        int ans = 0;
        for (auto& c : adj[x]) {
            ans = max(ans, dfs(c, k + 1));
        }
        dp[x] = ans;
        return ans;
    }

    int longestCycle(vector<int>& a) {
        this->n = a.size();
        adj.resize(n);
        m.assign(n, -1);
        dp.assign(n, -1);
      

        for (int i = 0; i < n; i++) {
            if (a[i] != -1 && a[i] < n) {
                adj[i].push_back(a[i]);
            }
        }

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] == -1) {
                ans = max(ans, dfs(i, 0));
            }
        }
        if(ans==0)
         ans=-1;
        return ans;
    }
};