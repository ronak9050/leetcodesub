class Solution {
public:

    vector<int> z_function(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    string longestPrefix(string s) {
        vector<int> pi=z_function(s);
        int st=-1,n=s.size();
        for(int i=n-1; i>=0; i--){
            if(pi[i]+i>=n) st=i;
        }
        if(st==-1) return "";
        return s.substr(st,n-st);
    }
};