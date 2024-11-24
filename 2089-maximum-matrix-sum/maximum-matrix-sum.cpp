#define ll long long

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        ll ans=0;
        int n=a.size(),ct=0,mn=1e9;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans=ans+abs(a[i][j]);
                mn=min(mn,abs(a[i][j]));
                if(a[i][j]<=0) ct++;
            }
        }
        if(ct&1) ans-=2*mn;
        return ans;
    }
};