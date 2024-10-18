class Solution {
public:
    int countMaxOrSubsets(vector<int>& a) {
        int ans=0,n=a.size(),ct=0;
        for(int i=0; i<n; i++) ans|=a[i];
        for(int i=1; i<(1<<n); i++){
            int cur=0;
            for(int j=0; j<n; j++){
                if(i&(1<<j)) cur|=a[j];
            }
            if(cur==ans) ct++;
        }
        return ct;
    }
};