class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int n=a.size();
        if(x<=a[0]) return {a.begin(),a.begin()+k};
        if(x>=a[n-1]) return {a.end()-k,a.end()};

        int l=min(abs(x-a[0]),abs(x-a[n-1])),h=max(abs(x-a[0]),abs(x-a[n-1])),st,end;
        while(l<=h){
            int mid=l+(h-l)/2;
            auto it=lower_bound(a.begin(),a.end(),x-mid)-a.begin();
            auto itr=upper_bound(a.begin(),a.end(),x+mid)-a.begin();
            if(itr-it>=k){
                st=it;
                end=itr;
                h=mid-1;
            }
            else l=mid+1;
        }
        // cout<<st<<" "<<end<<endl;
        while(end-st>k){
            if(abs(x-a[end-1])>=abs(x-a[st])) end--;
            else st++;
        }
        vector<int> ans(k);
        for(int i=st; i<end; i++) ans[i-st]=a[i];
        return ans;
    }
};