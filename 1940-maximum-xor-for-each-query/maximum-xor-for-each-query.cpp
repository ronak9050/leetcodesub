class Solution {
public:
    vector<int> getMaximumXor(vector<int>& a, int m) {
        int xr=0,n=a.size();
        for(int i=0; i<n; i++) xr=xr^a[i];
        vector<int> ans;
        for(int i=n-1; i>=0; i--){
            int cur=0;
            for(int j=0; j<m; j++){
                if(((xr>>j)&1)==0) cur|=(1<<j);
            }
            ans.push_back(cur);
            xr=xr^a[i];
        }
        return ans;
    }
};