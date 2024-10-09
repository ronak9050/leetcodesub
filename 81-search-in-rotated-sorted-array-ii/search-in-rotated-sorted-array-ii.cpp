class Solution {
public:
    bool search(vector<int>& a, int x) {
        int n=a.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(a[mid]==x) return 1;
            if(a[mid]==a[l] && a[mid]==a[h]){
                l++;
                h--;
                continue;
            }
            if(a[mid]>=a[l]){
                if(a[mid]>=x && a[l]<=x) h=mid-1;
                else l=mid+1;
            }
            else{
                if(a[mid]<=x && a[h]>=x) l=mid+1;
                else h=mid-1;
            }
        }
        
        return 0;
    }
};