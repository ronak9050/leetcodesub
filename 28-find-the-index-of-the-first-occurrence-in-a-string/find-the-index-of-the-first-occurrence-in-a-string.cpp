class Solution {
public:
    vector<int> z_function(string s){
        int n=s.size();
        vector<int> z(n);
        int l=0,r=0;
        for(int i=1; i<n; i++){
            if(i<r) z[i]=min(r-i,z[i-l]);
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
            if(i+z[i]>r){
                l=i;
                r=i+z[i];
            }
        }
        return z;
    }
    int strStr(string s, string t) {
        string tmp=t+'#'+s;
        vector<int> z=z_function(tmp);
        int n=t.size();
        for(int i=n+1; i<tmp.size(); i++){
            if(z[i]==n) return i-n-1; 
        }
        return -1;
    }
};