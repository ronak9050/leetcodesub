#define ll long long
class Solution {
public:
    int rangeSum(vector<int>& a, int n, int left, int right) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=0; i<n; i++){
            ll sum=0;
            for(int j=i; j<n; j++){
                sum=sum+a[j];
                pq.push(sum);
            }
        }
        for(int i=0; i<left-1; i++) pq.pop();
        ll ans=0,M=1e9+7;
        for(int i=left; i<=right; i++){
            ans=(ans+pq.top())%M;
            pq.pop();
        }
        return ans;
    }
};