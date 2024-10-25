class Solution {
public:
    bool prefix(string &a,string &b){
        int n=a.size(),m=b.size();
        if(m<=n) return 1;
        for(int i=0; i<n; i++) if(a[i]!=b[i]) return 1;
        if(b[n]!='/') return 1;
        return 0;
    }

    vector<string> removeSubfolders(vector<string>& a) {
        sort(a.begin(),a.end());
        vector<string> ans;
        ans.push_back(a[0]);
        for(int i=1; i<a.size(); i++){
            if(prefix(ans.back(),a[i])) ans.push_back(a[i]);
        }
        return ans;
    }
};