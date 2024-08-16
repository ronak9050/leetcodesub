class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int n=a.size(),ans=0;
        int mn=a[0][0],mx=a[0].back();
        for(int i=1; i<n; i++){
            ans=max({ans,abs(mn-a[i].back()),abs(mn-a[i][0]),abs(mx-a[i].back()),abs(mx-a[i][0])});
            mn=min(mn,a[i][0]);
            mx=max(mx,a[i].back());
        }
        return ans;
    }
};