class Solution {
public:
    bool func(int ct,int mask,int rem,int tot,int k,vector<int>&a,vector<vector<int>>&dp){
        int n=a.size();
        if(ct==0){
            int sum=0;
            for(int i=0; i<n; i++){
                if(!(mask&(1<<i))) sum+=a[i];
            }
            return sum==tot/k;
        }
        if(dp[ct][mask]!=-1) return dp[ct][mask];
        if(rem==0) return func(ct-1,mask,tot/k,tot,k,a,dp);
        int ans=0;
        for(int i=0; i<n; i++){
            if(rem>=a[i] && !(mask&(1<<i))){
                ans|=func(ct,mask|(1<<i),rem-a[i],tot,k,a,dp);
            }
        }
        return dp[ct][mask]=ans;
    }

    bool canPartitionKSubsets(vector<int>& a, int k) {
        int sum=accumulate(a.begin(),a.end(),0);
        if(sum%k) return 0;
        int n=a.size();
        vector<vector<int>> dp(k+1,vector<int>(1<<n,-1));
        return func(k-1,0,sum/k,sum,k,a,dp);
    }
};