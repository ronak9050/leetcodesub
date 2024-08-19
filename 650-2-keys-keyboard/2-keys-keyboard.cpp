class Solution {
public:
    int minSteps(int n) {
        vector<int> prime(n+1,1);
        vector<int> low(n+1,1);
        for(int i=2; i<=n; i++){
            if(prime[i]){
                for(int j=2*i; j<=n; j+=i){
                    prime[j]=0;
                    if(low[j]==1) low[j]=i;
                }
            }
        }
        vector<int> dp(n+1,0);
        for(int i=2; i<=n; i++){
            if(low[i]==1) dp[i]=i;
            else dp[i]=dp[i/low[i]]+low[i];
        }
        // for(int i=1; i<=n; i++) cout<<dp[i]<<" ";
        return dp[n];
    }
};