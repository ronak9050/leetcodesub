class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int ans=*max_element(a.begin(),a.end());
        int n=a.size(),ct=0,ret=0;

        for(int i=0; i<n; i++){
            if(a[i]==ans) ct++;
            else{
                ret=max(ret,ct);
                ct=0;
            }
        }
        ret=max(ret,ct);
        return ret;
    }
};