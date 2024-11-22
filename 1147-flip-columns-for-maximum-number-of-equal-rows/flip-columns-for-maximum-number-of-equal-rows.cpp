class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& a) {
        map<vector<int>,int> mp;
        int n=a.size(),m=a[0].size();
        for(int i=0; i<n; i++){
            if(a[i][0]==1){
                for(int j=0; j<m; j++){
                    if(a[i][j]) a[i][j]=0;
                    else a[i][j]=1;
                }
            }
            mp[a[i]]++;
        }

        int ans=0;
        for(auto &e:mp) ans=max(ans,e.second);
        return ans;
    }
};