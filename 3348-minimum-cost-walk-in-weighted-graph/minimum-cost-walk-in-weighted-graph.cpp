class Solution {
public:
    vector<int> par,val;
    int findpar(int u){
        if(u==par[u]) return u;
        return par[u]=findpar(par[u]);
    }

    void unite(int u,int v,int w){
        int paru=findpar(u);
        int parv=findpar(v);
        par[paru]=parv;
        val[paru]&=w;
        val[paru]&=val[parv];
        val[parv]=val[paru];
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query){
        par.resize(n+1);
        val.resize(n+1,(1<<30)-1);
        for(int i=0; i<n; i++) par[i]=i;

        for(auto &e:edges){
            unite(e[0],e[1],e[2]);
        }

        vector<int> ans;
        for(auto &e:query){
            if(findpar(e[0])==findpar(e[1])){
                ans.push_back(val[findpar(e[0])]);
            }
            else ans.push_back(-1);
        }
        return ans;        
    }
};