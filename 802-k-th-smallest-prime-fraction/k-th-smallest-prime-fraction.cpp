class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
        int n=a.size();
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
        for(int i=0; i<n-1; i++){
            pq.push({1.0*a[i]/a[n-1],{i,n-1}});
        }
        int ct=0,x,y;
        while(ct<k){
            auto it=pq.top();
            pq.pop();
            ct++;
            x=it.second.first;
            y=it.second.second;
            // cout<<x<<" "<<y<<endl;
            if(x+1!=y) pq.push({1.0*a[x]/a[y-1],{x,y-1}});
        }
        return {a[x],a[y]};
    }
};