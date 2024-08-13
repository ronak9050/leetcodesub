class Solution {
public:
    vector<vector<int>> final;
    vector<int> p;

    void func(int i,int target,vector<int>& a){
        if(target==0){
            final.push_back(p);
            return;
        }
        for(int j=i; j<a.size(); j++){
            if(j>i && a[j]==a[j-1]) continue;
            if(a[j]>target) break;
            p.push_back(a[j]);
            func(j+1,target-a[j],a);
            p.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        func(0,target,candidates);
        return final;
    }
};