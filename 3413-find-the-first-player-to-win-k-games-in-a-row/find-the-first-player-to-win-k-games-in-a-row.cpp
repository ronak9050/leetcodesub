class Solution {
public:
    int findWinningPlayer(vector<int>& a, int k) {
        int n=a.size();
        vector<int> ct(n,0);
        int ind=0;
        for(int i=1; i<n; i++){
            if(a[ind]<a[i]){
                ind=i;
            }
            ct[ind]++;
            if(ct[ind]==k) return ind;
        }
        int mx=0;
        for(int i=0; i<n; i++){
            if(a[i]>a[mx]) mx=i;
        }
        return mx;
    }
};