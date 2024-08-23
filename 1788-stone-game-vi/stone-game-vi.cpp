class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] + a[1] > b[0] + b[1];
    }

    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<vector<int>> pos(n);
        for (int i = 0; i < n; i++) {
            pos[i]={a[i],b[i]};
        }

        sort(pos.begin(), pos.end(), cmp);

        int sum=0;
        for (int i=0; i<n; i++) {
            if (i&1) sum-=pos[i][1];
            else sum+=pos[i][0];
        }

        if(sum) return (sum>0? 1:-1);
        return 0;
    }
};