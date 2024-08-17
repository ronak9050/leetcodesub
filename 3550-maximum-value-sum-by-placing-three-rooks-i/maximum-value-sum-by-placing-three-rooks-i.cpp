#define ll long long

class Solution {
public:
    
    ll func(int ct,int rem,priority_queue<vector<ll>> pq,vector<int> &row,vector<int> &col){
        if(rem==0) return 0;
        if(ct==0 || pq.empty()) return -1e15;
        
        ll ans=-1e15;
        auto cur=pq.top();
        while(pq.size() && (row[pq.top()[1]] || col[pq.top()[2]])){
            pq.pop();
        }
        if(pq.size()==0) return -1e15;
        cur=pq.top();
        pq.pop();
        
        ans=func(ct-1,rem,pq,row,col);
        row[cur[1]]=1;
        col[cur[2]]=1;
        ans=max(ans,cur[0]+func(ct-1,rem-1,pq,row,col));
        row[cur[1]]=0;
        col[cur[2]]=0;
        return ans;
    }
        
    long long maximumValueSum(vector<vector<int>>& a) {
        ll n=a.size(),m=a[0].size();
        priority_queue<vector<ll>> pq;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pq.push({a[i][j],i,j});
            }
        }
        vector<int> row(n,0),col(m,0);
        ll ans=func(6,3,pq,row,col);
        return ans;
    }
};