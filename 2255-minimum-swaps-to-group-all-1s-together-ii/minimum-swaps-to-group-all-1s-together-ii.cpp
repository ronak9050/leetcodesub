class Solution {
public:
    int minSwaps(vector<int>& a) {
        int n=a.size(),ct1=0;
        for(auto &e:a) if(e) ct1++;
        int curct=0;
        for(int i=0; i<ct1; i++) if(a[i]) curct++;
        int ans=ct1-curct;

        for(int i=0; i<n; i++){
            if(a[(i+ct1)%n]) curct++;
            if(a[i]) curct--;
            ans=min(ans,ct1-curct);
        }
        return ans;
    }
};