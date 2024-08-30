#define ll long long
class Solution {
public:
    void bfs(int ind,vector<vector<vector<ll>>>&g,vector<ll>&dp){
        set<vector<ll>> st;
        st.insert({dp[ind],ind});
        while(st.size()){
            auto it=st.begin();
            ll cur=it->at(1);
            ll dis=it->at(0);
            st.erase(it);
            for(auto &e:g[cur]){
                if(dp[e[0]]>e[1]+dp[cur]){
                    dp[e[0]]=e[1]+dp[cur];
                    st.insert({dp[e[0]],e[0]});
                }
            }
        }
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int s, int d, int t) {
        vector<vector<vector<ll>>> g(n);
        for(auto &e:edges){
            if(e[2]!=-1){
                g[e[0]].push_back({e[1],e[2]});
                g[e[1]].push_back({e[0],e[2]});
            }
        }

        vector<ll> dp1(n,1e15);
        dp1[s]=0;
        bfs(s,g,dp1);
        int f=0;
        if(dp1[d]==t) f=1;
        else if(dp1[d]<t) return {};

        vector<vector<int>> ans;
        for(auto &e:edges){
            if(e[2]!=-1) ans.push_back(e);
            else{
                if(f) ans.push_back({e[0],e[1],1000000003});
                else{
                    g[e[0]].push_back({e[1],1});
                    g[e[1]].push_back({e[0],1});
                    vector<ll> dp(n,1e15);
                    dp[s]=0;
                    bfs(s,g,dp);
                    int chn=1;
                    if(dp[d]<=t){
                        chn=t-dp[d]+1;
                        g[e[0]].back()={e[1],chn};
                        g[e[1]].back()={e[0],chn};
                        f=1;
                    }
                    ans.push_back({e[0],e[1],chn});
                }
            }
        }

        if(f) return ans;
        return {};
    }
};