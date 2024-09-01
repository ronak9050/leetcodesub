class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz=original.size();
        if(m*n!=sz) return {};
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0; i<sz; i++){
            ans[i/n][i%n]=original[i];
        }
        return ans;
    }
};