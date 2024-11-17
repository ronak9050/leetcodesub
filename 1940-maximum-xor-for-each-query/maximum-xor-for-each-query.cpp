class Solution {
public:
    vector<int> getMaximumXor(vector<int>& a, int m) {
        int xr=0,n=a.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            xr^=a[i];
            ans[i] = (((1<<m)-1)&xr)^((1<<m)-1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};