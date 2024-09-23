class Solution {
public:
    int minNumberOperations(vector<int>& a) {
        int n=a.size(),last=0,i=1,mx=a[0];
        int ans=0;
        while(i<n){
            while(i<n && a[i]>=a[i-1]) mx=max(mx,a[i++]);
            while(i<n && a[i]<=a[i-1]) i++;
            ans+=(mx-last);
            last=a[i-1];
            mx=a[i-1];
        }
        ans+=(mx-last);
        return ans;
    }
};