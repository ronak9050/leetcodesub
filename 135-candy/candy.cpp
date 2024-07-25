class Solution {
public:
    int candy(vector<int>& a) {
        int n=a.size(),ans=1,i=1;
        if(n==1) return 1;

        while(i<n){
            int ctp=0,ctn=0;
            while(i<n && a[i]>a[i-1]){
                ctp++;
                i++;
            }
            while(i<n && a[i]<a[i-1]){
                ctn++;
                i++;
            }
            if(ctp || ctn){
                int mx=max(ctp,ctn)+1,mn=min(ctp,ctn);
                ans+=(mx*(mx+1)/2+mn*(mn+1)/2-1);
            }
            else{
                i++;
                ans++;
            }
        }
        return ans;
    }
};