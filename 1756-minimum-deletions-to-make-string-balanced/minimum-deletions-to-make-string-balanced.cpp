class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int ct=0,ans=n,ct2=0;
        for(int i=0; i<n; i++){
            if(s[i]=='b') ct++;
        }
        for(int i=n-1; i>=0; i--){
            if(s[i]=='b') ct--;
            ans=min(ans,ct+ct2);
            if(s[i]=='a') ct2++;
        }
        
        return ans;
    }
};