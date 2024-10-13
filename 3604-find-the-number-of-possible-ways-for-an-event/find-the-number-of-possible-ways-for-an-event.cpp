#define ll long long
ll M=1e9+7;
class Solution {
public:
    ll power(ll a, ll b,ll c){
        ll ans=1;
        while(b){
            if(b&1) ans=(ans*a)%c;
            a=(a*a)%c;
            b=b>>1;
        }
        return ans;
    }

    vector<vector<ll>> func(ll n, ll x) {
        // Create a 2D vector to store Stirling numbers
        vector<vector<ll>> S(n + 1, vector<ll>(x + 1, 0));

        // Base case: S(0, 0) = 1
        S[0][0] = 1;

        // Fill the table using the recurrence relation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= x; j++) {
                S[i][j] = (j * S[i - 1][j] + S[i - 1][j - 1])%M;
            }
        }
        return S;
    }

    int numberOfWays(int n, int x, int y) {
        vector<ll> fac(max(n,x)+1,1);
        for(int i=1;i<=max(n,x); i++){
            fac[i]=(fac[i-1]*i)%M;
        }

        ll ans=0,mul=1;
        vector<vector<ll>> s = func(n,x);
        if(n==5) cout<<s[5][1]<<endl;
        for(ll i=1; i<=min(x,n); i++){
            ll xci=(fac[x]*power(fac[x-i],M-2,M))%M*power(fac[i],M-2,M)%M;
            ll cur=(s[n][i]*xci%M*fac[i])%M;
            mul=(mul*y)%M;
            ans=(ans+cur*mul%M)%M;
        }
        return ans;
    }
};