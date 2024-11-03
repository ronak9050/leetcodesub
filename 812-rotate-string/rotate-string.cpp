class Solution {
public:
    void kmp(string &s,vector<int>&ans){
        int n=s.size();
        for(int i=1; i<n; i++){
            int j=ans[i-1];
            while(j>0 && s[i]!=s[j]){
                j=ans[j-1];
            }
            if(s[i]==s[j]) j++;
            ans[i]=j;
        }
    }
    bool rotateString(string s, string t) {
        int n=s.size(),m=t.size();
        if(n!=m) return 0;
        string tmp=s+'#'+t;
        vector<int> ans(2*n+1,0);
        string tmp2=t+'#'+s;
        vector<int> ans2(2*n+1,0);
        kmp(tmp,ans);
        kmp(tmp2,ans2);
        return ans[2*n]+ans2[2*n]>=n;
    }
};