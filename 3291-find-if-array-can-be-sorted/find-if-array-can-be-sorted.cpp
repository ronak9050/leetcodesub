class Solution {
public:
    bool canSortArray(vector<int>& a) {
        int n=a.size();
        int i=1,j=0;
        for(; i<n; i++){
            if(__builtin_popcount(a[i])!=__builtin_popcount(a[i-1])){
                sort(a.begin()+j,a.begin()+i);
                j=i;
            }
        }
        sort(a.begin()+j,a.begin()+i);
        return is_sorted(a.begin(),a.end());
    }
};