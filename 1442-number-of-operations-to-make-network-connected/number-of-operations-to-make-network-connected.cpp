class Solution {
public:
    int findpar(int u,vector<int> &par){
        if(par[u]==u) return u;
        return par[u]=findpar(par[u],par);
    }
    void unite(int u,int v,vector<int>&par){
        int paru=findpar(u,par);
        int parv=findpar(v,par);
        par[paru]=parv;
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        vector<int> par(n);
        for(int i=0; i<n; i++) par[i]=i;

        int extr=0;
        for(auto &e:con){
            if(findpar(e[0],par)!=findpar(e[1],par)) unite(e[0],e[1],par);
            else extr++;
        }

        int ct=0;
        for(int i=0; i<n; i++) if(par[i]==i) ct++;
        if(extr>=ct-1) return ct-1;
        return -1;
    }
};