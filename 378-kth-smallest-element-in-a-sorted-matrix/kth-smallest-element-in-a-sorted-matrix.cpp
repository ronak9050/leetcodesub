class Solution {
public:
    bool check(int mid,int k,vector<vector<int>>&a){
        int n=a.size(),ct=0;
        for(int i=0; i<n; i++){
            auto it=upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
            ct+=it;
        }
        if(ct>=k) return 1;
        return 0;
    }

    int kthSmallest(vector<vector<int>>& a, int k) {
        int n=a.size();
        int l=a[0][0],h=a[n-1][n-1]+1,ans;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(mid,k,a)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};