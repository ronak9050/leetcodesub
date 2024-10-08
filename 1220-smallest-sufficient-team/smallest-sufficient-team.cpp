#define ll long long
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& pp){
        map<string,int> mp;
        int m=req.size();
        int ct=0;
        for(auto &e:req){
            mp[e]=ct;  
            ct++;
        }
        int n=pp.size();
        vector<ll> a(n,0);
        for(int i=0; i<n; i++){
            for(auto &e:pp[i]){
                a[i]=a[i]|(1ll<<mp[e]);
            }
        }
        
        vector<ll> dp(1<<m,(1ll<<n)-1);
        dp[0]=0;
        // for(int i=1; i<(1<<m); i++){
        //     for(int j=0; j<n; j++){
        //         ll sm = (i & (~a[j]));
        //         if(sm!=i){
        //             ll pos = dp[sm]|(1ll<<j);
        //             if(__builtin_popcount(pos)<__builtin_popcount(dp[i])) dp[i]=pos;
        //         }
        //     }
        // }
        for (int i = 1; i < (1 << m); i++) {
            for (int j = 0; j < n; j++) {
                int smallerSkillsMask = i & ~a[j];
                if (smallerSkillsMask != i) {
                    long long peopleMask = dp[smallerSkillsMask] | (1LL << j);
                    if (__builtin_popcountll(peopleMask) < __builtin_popcountll(dp[i])) {
                        dp[i] = peopleMask;
                    }
                }
            }
        }
        vector<int> ans;
        ll num=dp[(1<<m)-1];
        for(int i=0; i<n; i++){
            if((num>>i)&1) ans.push_back(i);
        }
        return ans;
    }
};