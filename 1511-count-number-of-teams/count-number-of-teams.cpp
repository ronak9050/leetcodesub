class Solution {
public:
    int numTeams(vector<int>& a) {
        int ans=0,n=a.size();
        vector<int> fwd(n,0),bkd(n,0);
        for(int i=0; i<n; i++){
            int cur=0;
            for(int j=i+1; j<n; j++){
                if(a[j]>a[i]) cur++;
            }
            fwd[i]=cur;
            cur=0;
            for(int j=0; j<i; j++){
                if(a[j]>a[i]) cur++;
            }
            bkd[i]=cur;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(a[j]>a[i]){
                    ans+=fwd[j];
                }
            }
            for(int j=0; j<i; j++){
                if(a[j]>a[i]){
                    ans+=bkd[j];
                }
            }
        }
        return ans;
    }
};