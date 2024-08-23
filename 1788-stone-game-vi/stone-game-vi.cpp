class Solution {
public:

    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        priority_queue<vector<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({a[i]+b[i],a[i],b[i]});
        }

        int sum=0;
        for (int i=0; i<n; i++) {
            if (i&1) sum-=pq.top()[2];
            else sum+=pq.top()[1];
            pq.pop();
        }

        if(sum) return (sum>0? 1:-1);
        return 0;
    }
};