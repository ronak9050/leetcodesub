#define ll long long
class Solution {
public:
    long long maxSpending(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
        for(int i=0; i<n; i++){
            pq.push({a[i][m-1],i,m-1});
        }
        ll ans=0,d=1;
        while(pq.size()){
            auto cur=pq.top();
            pq.pop();
            ans+=cur[0]*d;
            d++;
            if(cur[2]>0) pq.push({a[cur[1]][cur[2]-1],cur[1],cur[2]-1});
        }
        return ans;
    }
};