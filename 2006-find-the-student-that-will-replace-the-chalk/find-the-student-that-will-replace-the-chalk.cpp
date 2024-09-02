#define ll long long
class Solution {
public:
    int chalkReplacer(vector<int>& a, int k) {
        ll sum=accumulate(a.begin(),a.end(),0ll);
        ll rem=k%sum;
        int n=a.size();
        for(int i=0; i<n; i++){
            if(a[i]>rem) return i;
            else rem-=a[i];
        }
        return 0;
    }
};