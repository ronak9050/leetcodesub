class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        for(auto e:s){
            int n=ans.size();
            if(ans.size()>1 && ans[n-1]==e && ans[n-2]==e) continue;
            ans.push_back(e);
        }
        return ans;
    }
};