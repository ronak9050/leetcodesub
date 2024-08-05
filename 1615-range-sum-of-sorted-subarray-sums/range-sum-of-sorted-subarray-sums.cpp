#define ll long long
ll M=1e9+7;
class Solution {
public:
    pair<ll,ll> check(ll mid,ll k,vector<int>&a){
        ll sum=0,j=0,ct=0,wsum=0,totsum=0,n=a.size();
        for(int i=0; i<n; i++){
            sum=sum+a[i];
            wsum=wsum+a[i]*1ll*(i-j+1);
            while(sum>mid){
                wsum-=sum;
                sum-=a[j];
                j++;
            }
            ct=ct+(i-j+1);
            totsum=totsum+wsum;
        }
        return {ct,totsum};
    }

    ll func(int k,vector<int>&a){
        int n=a.size();
        ll l=*min_element(a.begin(),a.end());
        ll h=0;
        for(auto &e:a) h=h+e;
        while(l<=h){
            ll mid=(l+h)/2;
            pair<ll,ll> cur=check(mid,k,a);
            if(cur.first>=k) h=mid-1;
            else l=mid+1;
        }
        pair<ll,ll> fin=check(l,k,a);
        return fin.second-l*(fin.first-k);
    }

    int rangeSum(vector<int>& a, int n, int left, int right) {
        return (func(right,a)-func(left-1,a))%M;
    }
};