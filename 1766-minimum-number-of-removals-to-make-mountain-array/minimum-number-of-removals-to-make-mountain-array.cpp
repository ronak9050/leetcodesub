class Solution {
public:
    void lis(vector<int>&a,vector<int>&dp){
        int n=a.size();
        vector<int> v;
        for(int i=0; i<n; i++){
            auto it=lower_bound(v.begin(),v.end(),a[i]);
            if(it==v.end()) v.push_back(a[i]);
            else{
                v[it-v.begin()]=a[i];
            }
            dp[i]=v.size()-1;
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