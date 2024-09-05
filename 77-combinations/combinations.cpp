class Solution {
public:
    vector<vector<int>> ans;
    void func(int j,int k,vector<int> &cur){
        if(j==0) {
            if(cur.size()==k) ans.push_back(cur);
            return;
        }
        func(j-1,k,cur);
        cur.push_back(j);
        func(j-1,k,cur);
        cur.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        func(n,k,cur);
        return ans;
    }
};