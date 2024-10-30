class Solution {
public:
    void lis(vector<int>&a,vector<int>&dp){
        int n=a.size();
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(a[i]>a[j]) dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }

    int minimumMountainRemovals(vector<int>& a) {
        int n=a.size();
        vector<int> fdp(n,0),bdp(n,0);
        lis(a,fdp);
        reverse(a.begin(),a.end());
        lis(a,bdp);
        reverse(bdp.begin(),bdp.end());

        int ans=n;
        for(int i=0; i<n; i++){
            if(fdp[i] && bdp[i]) ans=min(ans,n-(fdp[i]+bdp[i]+1));
        }
        return ans;
    }
};