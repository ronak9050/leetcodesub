class Solution {
public:
    bool static cmp(vector<int>&a,vector<int>&b){
        return a[0]*b[1]<a[1]*b[0];
    }

    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        int n=q.size();
        vector<vector<int>> a(n);
        for(int i=0; i<q.size(); i++){
            a[i]={w[i],q[i]};
        }
        sort(a.begin(),a.end(),cmp);
        priority_queue<int> pq;
        int sum=0;
        for(int i=0; i<k; i++){
            sum+=a[i][1];
            pq.push(a[i][1]);
        }
        double ans=sum*(1.0*(a[k-1][0])/a[k-1][1]);
        for(int i=k; i<n; i++){
            sum+=a[i][1];
            pq.push(a[i][1]);
            sum-=pq.top();
            pq.pop();
            ans=min(ans,sum*(1.0*(a[i][0])/a[i][1]));
        }
        return ans;
    }
};