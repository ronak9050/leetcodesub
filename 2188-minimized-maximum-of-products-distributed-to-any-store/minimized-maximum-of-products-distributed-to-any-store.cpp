class Solution {
public:
    bool check(int mid,int n,vector<int> a){
        int m=a.size();
        for(int i=0,j=0; i<n; i++){
            if(j==m) return 1;
            if(a[j]<=mid) j++;
            else a[j]-=mid;
            if(j==m) return 1;
        }
        return 0;
    }

    int minimizedMaximum(int n, vector<int>& a) {
        int m=a.size();
        int l=0,h=INT_MAX,ans=INT_MAX;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(mid,n,a)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }

        return ans;
    }
};