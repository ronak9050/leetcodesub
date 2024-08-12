class Solution {
public:
    int countCompleteDayPairs(vector<int>& a) {
        vector<int> ct(24,0);
        int n=a.size(),ans=0;
        for(int i=0; i<n; i++){
            int rem=a[i]%24;
            if(rem) ans+=ct[24-rem];
            else ans+=ct[rem];
            ct[rem]++;
        }
        return ans;
    }
};