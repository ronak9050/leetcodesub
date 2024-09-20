class Solution {
public:
    void kmp(string s,vector<int>&pi){
        int n=s.size();
        for(int i=1; i<n; i++){
            int j=pi[i-1];
            while(j!=0 && s[i]!=s[j]){
                j=pi[j-1];
            }
            if(s[i]==s[j]) j++;
            pi[i]=j;
        }
    }
    string shortestPalindrome(string s) {
        if(s.size()==0) return "";
        string tmp=s;
        reverse(tmp.begin(),tmp.end());
        int n=s.size();

        string t=s+'#'+tmp;
        vector<int> pi(t.size(),0);
        kmp(t,pi);

        int ans=n-pi[t.size()-1];
        // for(int i=n+1; i<t.size(); i++){
        //     if(pi[i]+i>=t.size()) ans=min(ans,n-pi[i]);
        // }
        string add=s.substr(n-ans,ans);
        reverse(add.begin(),add.end());
        string ret=add+s;
        return ret;
    }
};