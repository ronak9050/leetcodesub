class Solution {
public:
    int largestCombination(vector<int>& a) {
        int n=a.size();
        int ans=1;
        for(int j=0; j<32; j++){
            int ct=0;
            for(int i=0; i<n; i++){
                if((a[i]>>j)&1) ct++;
            }
            ans=max(ans,ct);
        }
        
        return ans;
    }
};