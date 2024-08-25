#define ll long long
class Solution {
public:
    long long maxSpending(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<int> ans(m*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) ans[i*m+j]=a[i][j];
        }
        sort(ans.begin(),ans.end());
        ll ret=0;
        for(ll i=0; i<m*n; i++) ret+=(i+1)*ans[i];
        return ret;
    }
};