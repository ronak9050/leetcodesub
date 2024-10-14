#define ll long long
ll M=1e9+7;

class Solution {
public:
    map<char,int> mp={{'F',0},{'W',1},{'E',2}};

    int check(int s,int t){
        if(s==0){
            if(t==1) return 1;
            else if(t==2) return -1;
        }
        else if(s==1){
            if(t==2) return 1;
            else if(t==0) return -1;
        }
        else if(s==2){
            if(t==0) return 1;
            else if(t==1) return -1;
        }
        return 0;
    }

    ll func(int ind,int ct,int last,string &s,vector<vector<vector<ll>>>&dp){
        int n=s.size();
        if(ind>=n) return ct>n;
        if(dp[ind][ct][last]!=-1) return dp[ind][ct][last];

        ll ans=0;
        for(int i=0; i<3; i++){
            if(last!=i) ans=(ans+func(ind+1,ct+check(mp[s[ind]],i),i,s,dp))%M;
        }

        return dp[ind][ct][last]=ans;
    }

    int countWinningSequences(string s) {
        int n=s.size();
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(2*n+1,vector<ll>(4,-1)));
        return func(0,n,3,s,dp);
    }
};