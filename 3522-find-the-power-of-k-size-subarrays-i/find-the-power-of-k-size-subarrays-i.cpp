class Solution {
public:
    vector<int> resultsArray(vector<int>& a, int k) {
        int n=a.size();
        vector<int> pos(n,0);
        pos[0]=1;
        for(int i=1; i<n; i++){
            if(a[i]-1==a[i-1]) pos[i]=1;
        }
        for(int i=1; i<n; i++){
            if(pos[i]) pos[i]+=pos[i-1];
        }
        vector<int> ans(n-k+1);
        for(int i=k-1; i<n; i++){
            if(pos[i]>=k-1) ans[i-k+1]=a[i];
            else ans[i-k+1]=-1;
        }
        return ans;
    }
};