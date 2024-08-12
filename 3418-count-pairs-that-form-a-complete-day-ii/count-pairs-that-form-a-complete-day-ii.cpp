#define ll long long
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& a) {
        vector<ll> ct(24,0);
        ll n=a.size(),ans=0;
        for(int i=0; i<n; i++){
            ll rem=a[i]%24;
            if(rem) ans+=ct[24-rem];
            else ans+=ct[rem];
            ct[rem]++;
        }
        return ans;
    }
};