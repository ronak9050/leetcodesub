#define ll long long

class Solution {
public:
    ll func(int ind,vector<ll>&a,vector<ll>&dp,unordered_map<ll,ll> &mp){
        int n=a.size();
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        ll ans=func(ind+1,a,dp,mp);
        int i=ind;
        while(i<n && a[i]<a[ind]+3) i++;
        ans=max(ans,a[ind]*mp[a[ind]]+func(i,a,dp,mp));
        return dp[ind]=ans;
    }

    long long maximumTotalDamage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<ll,ll> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]++;
        vector<ll> a(mp.size());
        int i=0;
        for(auto &e:mp) a[i++]=e.first;
        sort(a.begin(),a.end());

        int n=a.size();
        vector<ll> dp(n,-1);
        return func(0,a,dp,mp);
    }
};