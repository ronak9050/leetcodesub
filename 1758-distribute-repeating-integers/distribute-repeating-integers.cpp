class Solution {
public:
    int dp[50][1<<10];

    bool check(int ind,int mask,vector<int> &ct,vector<int>&q){
        int n=q.size(),m=ct.size();
        if(mask==(1<<n)-1) return 1;
        if(ind>=m) return 0;
        if(dp[ind][mask]!=-1) return dp[ind][mask];
        
        int ans=check(ind+1,mask,ct,q);
        for(int i=mask; i<(1<<n); i++){
            if(((i^mask)&mask)==0){
                int cur=i^mask,sum=0;
                for(int j=0; j<n; j++){
                    if(cur&(1<<j)) sum+=q[j];
                }
                if(sum<=ct[ind]) ans|=check(ind+1,mask|i,ct,q);
            }
        }

        return dp[ind][mask]=ans;
    }

    bool canDistribute(vector<int>& a, vector<int>& q) {
        memset(dp,-1,sizeof(dp));
        vector<int> mp(1001,0);
        for(int e:a) mp[e]++;
        vector<int> ct;
        for(int i=0; i<=1000; i++) if(mp[i]) ct.push_back(mp[i]);
        return check(0,0,ct,q);
    }
};