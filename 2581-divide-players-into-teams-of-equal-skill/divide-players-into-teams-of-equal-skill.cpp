#define ll long long

class Solution {
public:
    long long dividePlayers(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        ll req=a[0]+a[n-1],ans=0;
        for(int i=0; i<n/2; i++){
            if(a[i]+a[n-i-1]==req) ans+=(a[i]*1ll*a[n-i-1]);
            else return -1;
        }
        return ans;
    }
};