class Solution {
public:
    bool check(int mid,int n,vector<int> &a){
        long ct=0;
        for(int i=0; i<a.size(); i++) ct+=ceil(a[i]*1.0/mid);
        return ct<=n;
    }

    int minimizedMaximum(int n, vector<int>& a) {
        int m=a.size();
        int l=1,h=INT_MAX,ans=INT_MAX;
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