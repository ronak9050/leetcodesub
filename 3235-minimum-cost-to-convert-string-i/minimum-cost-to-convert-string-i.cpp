
#define ll long long
class Solution {
public:
    ll minimumCost(string s,string t,vector<char>& org,vector<char>& chn,vector<int>& cost) {
        vector<vector<ll>> c(26,vector<ll>(26,1e13));
        ll n=org.size(),ans=0;
        for(int i=0; i<n; i++){
            c[org[i]-'a'][chn[i]-'a']=min(c[org[i]-'a'][chn[i]-'a'],cost[i]+0ll);
        }
        for(int via=0; via<26; via++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    if(i==j) c[i][j]=0;
                    c[i][j]=min(c[i][j],c[i][via]+c[via][j]);
                }
            }
        }
        n=s.size();
        for(int i=0; i<n; i++){
            if(c[s[i]-'a'][t[i]-'a']<1e13){
                ans+=(c[s[i]-'a'][t[i]-'a']);
            }
            else return -1;
        }
        return ans;
    }
};