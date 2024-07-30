class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> fwd(n,0),bkd(n,0);
        int ct=0;
        for(int i=0; i<n; i++){
            fwd[i]=ct;
            if(s[i]=='b') ct++;
        }
        ct=0;
        for(int i=n-1; i>=0; i--){
            bkd[i]=ct;
            if(s[i]=='a') ct++;
        }
        int ans=n;
        for(int i=0; i<n; i++){
            ans=min(ans,bkd[i]+fwd[i]);
        }
        return ans;
    }
};