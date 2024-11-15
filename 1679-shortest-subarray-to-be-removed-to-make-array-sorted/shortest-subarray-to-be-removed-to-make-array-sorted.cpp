class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int n=a.size();
        vector<int> v={a[n-1]};
        for(int i=n-2; i>=0; i--){
            if(a[i]<=v.back()) v.push_back(a[i]);
            else break;
        }
        reverse(v.begin(),v.end());
        int ans=n-v.size();
        for(int i=0; i<n; i++){
            if(i && a[i]<a[i-1]) break;
            auto it=lower_bound(v.begin(),v.end(),a[i])-v.begin();
            int num=v.size()-it;
            ans=min(ans,n-(i+1+num));
        }
        return max(0,ans);
    }
};