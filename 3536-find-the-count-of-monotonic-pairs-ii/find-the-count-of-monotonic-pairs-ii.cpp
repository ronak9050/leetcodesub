#define ll long long
ll M=1e9+7;
class Solution {
public:
    
    int countOfPairs(vector<int>& a) {
        int n=a.size();
        vector<vector<ll>> dp(n,vector<ll>(1005,0));
        for(int i=0; i<=a[0]; i++) dp[0][i]=i+1;
        for(int i=a[0]+1; i<=1000; i++) dp[0][i]=dp[0][i-1];
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=a[i]; j++){
                int st=min(a[i-1]-(a[i]-j),j);
                if(st>=0){
                    dp[i][j]=dp[i-1][st];
                }
            }
            for(int j=1; j<=1000; j++) dp[i][j]=(dp[i][j]+dp[i][j-1])%M;
        }
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<=4; j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        
        return dp[n-1][a[n-1]];
    }
};