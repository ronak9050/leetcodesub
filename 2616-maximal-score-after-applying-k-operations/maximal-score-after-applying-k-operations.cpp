#define ll long long
class Solution {
public:
    long long maxKelements(vector<int>& a, int k) {
        priority_queue<int> pq;
        for(auto &e:a) pq.push(e);
        ll ans=0;
        while(k){
            int cur=pq.top();
            ans=ans+cur;
            pq.pop();
            pq.push(ceil(cur/3.0));
            k--;
        }
        return ans;
    }
};