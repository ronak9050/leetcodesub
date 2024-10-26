class Solution {
public:
    int dp[50][1<<15];

    void precom(string &s,vector<int>&ct){
        for(auto e:s) ct[e-'a']++;
    }

    int func(int ind,int mask,string &t,vector<string> &s){
        int n=t.size(),m=s.size();
        if(mask==(1<<n)-1) return 0;
        if(ind>=m) return 100;
        if(dp[ind][mask]!=-1) return dp[ind][mask];
        int ans=func(ind+1,mask,t,s);
        vector<int> ct(26,0);
        precom(s[ind],ct);
        int f=0,cp=mask;
        for(int i=0; i<n; i++){
            if(ct[t[i]-'a'] && !(cp&(1<<i))){
                cp|=(1<<i);
                ct[t[i]-'a']--;
                f=1;
            }
        }

        if(f) ans=min(ans,1+func(ind,cp,t,s));

        return dp[ind][mask]=ans;
    }

    int minStickers(vector<string>& s, string t) {
        vector<int> ct(26,0);
        for(auto &e:s){
            for(auto f:e) ct[f-'a']=1;
        }
        for(auto e:t) if(!ct[e-'a']) return -1;
        memset(dp,-1,sizeof(dp));
        return func(0,0,t,s);
    }
};