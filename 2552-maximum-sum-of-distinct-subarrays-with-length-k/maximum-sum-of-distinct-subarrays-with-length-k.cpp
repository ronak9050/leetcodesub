#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& a, int k) {
        int n=a.size();
        if(k==1) return *max_element(a.begin(),a.end());
        ll ans=0,sum=0;
        vector<int> mp(100003,0);
        int ct=0;
        for(int i=0; i<k; i++){
            if(mp[a[i]]) ct++;
            mp[a[i]]++;
            sum=sum+a[i];
        }
        
        if(!ct) ans=sum;

        for(int i=k; i<n; i++){
            mp[a[i-k]]--;
            if(mp[a[i-k]]) ct--;
            if(mp[a[i]]) ct++;
            mp[a[i]]++;
            sum=sum+a[i]-a[i-k];
            cout<<ct<<" "<<sum<<endl;
            if(!ct) ans=max(ans,sum);
        }

        return ans;
    }
};