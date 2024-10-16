class Solution {
public:
    int findpar(int u,vector<int>&par){
        if(par[u]==u) return u;
        return par[u]=findpar(par[u],par);
    }
    void unite(int u,int v,vector<int>&par){
        par[u]=v;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> par(n+1);
        for(int i=0; i<=n; i++) par[i]=i;
        for(auto &e:edges){
            int paru=findpar(e[0],par);
            int parv=findpar(e[1],par);
            if(paru==parv) return e;
            unite(paru,parv,par);
        }
        return edges.back();
    }
};