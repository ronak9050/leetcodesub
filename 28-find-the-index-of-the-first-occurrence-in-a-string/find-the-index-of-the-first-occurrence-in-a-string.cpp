class Solution {
public:
    vector<int> kmp(string s){
        int n=s.size();
        vector<int> pi(n);
        
        for(int i=1; i<n; i++){
            int j=pi[i-1];
            while(j!=0 && s[i]!=s[j]){
                j=pi[j-1];
            }
            if(s[i]==s[j]) j++;
            pi[i]=j;
        }

        return pi;
    }
    int strStr(string s, string t) {
        string tmp=t+'#'+s;
        vector<int> pi=kmp(tmp);
        int n=t.size();
        for(int i=n+1; i<tmp.size(); i++){
            if(pi[i]==n) return i-2*n; 
        }
        return -1;
    }
};