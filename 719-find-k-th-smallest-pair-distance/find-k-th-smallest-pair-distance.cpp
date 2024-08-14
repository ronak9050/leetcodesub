class Solution {
public:
    bool check(int mid,int k,vector<int>&a){
        int ct=0,n=a.size();
        for(int i=0; i<n; i++){
            auto it=upper_bound(a.begin(),a.end(),a[i]+mid)-a.begin();
            ct+=(it-1-i);
        }
        // cout<<mid<<" "<<ct<<endl;
        if(ct>=k) return 1;
        return 0;
    }

    int smallestDistancePair(vector<int>& a, int k) {
        int n=a.size();
        sort(a.begin(),a.end());
        int l=0,h=a[n-1]+1;
        int ans;
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