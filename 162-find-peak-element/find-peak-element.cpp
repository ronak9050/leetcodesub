class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n=a.size();
        int l=0,h=n-1,ans;
        while(l<=h){
            int mid=(l+h)/2;
            if(mid==n-1) return mid;
            if(a[mid]>a[mid+1]){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};