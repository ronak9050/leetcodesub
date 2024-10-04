#define ll long long

class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) {
        ll ans=0,n=a.size();
        int ct=0,i=n-1;
        sort(a.begin(),a.end());
        while(ct!=k){
            ans=ans+max(a[i]-ct,0);
            i--;
            ct++;
        }
        return ans;
    }
};