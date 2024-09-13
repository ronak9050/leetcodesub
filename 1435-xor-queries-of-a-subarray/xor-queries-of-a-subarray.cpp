class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& q) {
        int n=a.size();
        vector<int> hsh(n+1,0);
        for(int i=1; i<n+1; i++){
            hsh[i]=hsh[i-1]^a[i-1];
        }
        vector<int> ans(q.size());
        for(int i=0; i<q.size(); i++){
            ans[i]=hsh[q[i][0]]^hsh[q[i][1]+1];
        }
        return ans;
    }
};