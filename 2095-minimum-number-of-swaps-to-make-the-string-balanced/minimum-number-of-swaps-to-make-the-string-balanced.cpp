class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int ans=0,ct=0;
        for(int i=0; i<n; i++){
            if(s[i]=='[') ct++;
            else{
                if(ct) ct--;
                else ans++;
            }
        }
        return ceil(ans/2.0);
    }
};