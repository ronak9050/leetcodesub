class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int n=a.size(),i;
        int fmx=0,bmx=0,ans=0;
        for( i=1; i<n; i++){
            fmx=max(fmx-1,a[i-1]-1);
            ans=max(ans,fmx+a[i]);
        }
        for( i=n-2; i>=0; i--){
            bmx=max(bmx-1,a[i+1]-1);
            ans=max(ans,bmx+a[i]);
        }
        return ans;
    }
};