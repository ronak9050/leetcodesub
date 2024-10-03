#define ll long long

class Solution {
public:
    int minSubarray(vector<int>& a, int p) {
        int n=a.size();
        ll sum=accumulate(a.begin(),a.end(),0ll);
        if(sum<p) return -1;

        ll ans=sum%p? n:0;
        unordered_map<ll,ll> mp;
        mp[0]=-1;
        ll cur=0;
        for(int i=0; i<n; i++){
            cur=cur+a[i];
            ll req=(cur%p-sum%p+p)%p;
            if(mp.find(req)!=mp.end()) ans=min(ans,i-mp[req]);
            mp[cur%p]=i;
        }
        return ans==n? -1:ans;
    }
};