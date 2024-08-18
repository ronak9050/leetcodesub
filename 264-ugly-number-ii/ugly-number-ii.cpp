#define ll long long
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        pq.push(1);
        unordered_map<ll,int> mp;
        while(n){
            ll cur=pq.top();
            pq.pop();
            if(mp[cur]) continue;
            n--;
            mp[cur]=1;
            if(n==0) return cur;
            if(!mp[cur*2]) pq.push(cur*2);
            if(!mp[cur*3]) pq.push(cur*3);
            if(!mp[cur*5]) pq.push(cur*5);
        }
        return 1;
    }
};