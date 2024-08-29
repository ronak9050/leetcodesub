#define ll long long
class Solution {
public:
    ll func(int x,vector<int>&a){
        ll n=a.size();
        vector<pair<int,int>> dp((1<<n));
        dp[0]={1,0};
        for(int i=1;i<(1<<n); i++){
            dp[i]={n+1,0};
            for(int j=0; j<n; j++){
                if(i&(1<<j)){
                    auto cur=dp[i^(1<<j)];
                    if(cur.second+a[j]<=x) cur.second+=a[j];
                    else{
                        cur.first++;
                        cur.second=a[j];
                    }
                    dp[i]=min(dp[i],cur);
                }
            }
        }
        return dp[(1<<n)-1].first;
    }
    int minimumTimeRequired(vector<int>& a, int k) {
        int sum=accumulate(a.begin(),a.end(),0);
        int l=*max_element(a.begin(),a.end()),h=sum,ans=sum;
        while(l<=h){
            int mid=(l+(h-l)/2);
            if(func(mid,a)<=k){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};