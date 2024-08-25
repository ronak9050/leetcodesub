class Solution {
public:
    int stoneGameVIII(vector<int>& st) {
        partial_sum(begin(st), end(st), begin(st));
        int res = st.back();
        for (int i = st.size() - 2; i > 0; --i)
            res = max(res, st[i] - res);
        return res;
    }
};