class Solution {
public:
    vector<vector<int>> ans;
    void func(int rem,int st,int sum,vector<int>&cur){
        if(rem==0 || sum==0){
            if(rem==0 && sum==0) ans.push_back(cur);
            return;
        }
        for(int i=st; i<10; i++){
            if(sum-i>=0){
                cur.push_back(i);
                func(rem-1,i+1,sum-i,cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        func(k,1,n,cur);
        return ans;            
    }
};