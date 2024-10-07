class Solution {
public:
    void merge(int l,int r,vector<pair<int,int>>&a,vector<int>&ans){
        vector<pair<int,int>> tmp;
        int mid=(l+r)/2;
        for(int i=l; i<=mid; i++){
            int it=lower_bound(a.begin()+mid+1,a.begin()+r+1,pair<int,int>(a[i].first,0))-a.begin();
            it-=(mid+1);
            ans[a[i].second]+=it;
        }
        int i=l,j=mid+1;
        while(i<=mid || j<=r){
            if(i<=mid && j<=r){
                if(a[i].first<a[j].first){
                    tmp.push_back(a[i]);
                    i++;
                }
                else{
                    tmp.push_back(a[j]);
                    j++;
                }
            }
            else if(i<=mid){
                tmp.push_back(a[i]);
                i++;
            }
            else{
                tmp.push_back(a[j]);
                j++;
            }
        }
        for(int i=l; i<=r; i++){
            a[i]=tmp[i-l];
        }
    }

    void mergesort(int l,int r,vector<pair<int,int>>&a,vector<int>&ans){
        if(l==r) return;
        int mid=(l+r)/2;
        mergesort(l,mid,a,ans);
        mergesort(mid+1,r,a,ans);
        merge(l,r,a,ans);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> a(nums.size());
        for(int i=0; i<nums.size(); i++){
            a[i]={nums[i],i};
        }
        vector<int> ans(nums.size(),0);
        mergesort(0,n-1,a,ans);
        return ans;
    }
};