class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size(),ct=0,ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') ct++;
            else{
                if(ct) ct--;
                else ans++;
            }
        }
        ans+=ct;
        return ans;
    }
};