#define ll long long

class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        vector<ll> mul;
        ll ans=0,n=a.size();
        int mx=*max_element(a.begin(),a.end());
        for(int i=0; i<n; i++){
            if(a[i]==mx){
                mul.push_back(i+1);
            }
        }
        n=mul.size();
        mul.push_back(a.size()+1);
        
        for(int i=0; i<=n-k; i++){
            ans=ans+(mul[i]*1ll*(mul[i+k]-mul[i+k-1]));
        }
        return ans;
    }
};