class DSU{
    vector<int> sz,par;
    public:
    DSU(int n){
        sz.resize(n+1,1);
        par.resize(n+1);
        for(int i=0; i<n+1; i++) par[i]=i;
    }

    int findpar(int u){
        if(par[u]==u) return u;
        return par[u]=findpar(par[u]);
    }

    void unite(int u,int v){
        int paru=findpar(u);
        int parv=findpar(v);
        if(paru==parv) return;

        if(sz[paru]>sz[parv]){
            sz[paru]+=sz[parv];
            par[parv]=paru;
        }
        else{
            sz[parv]+=sz[paru];
            par[paru]=parv;
        }
    }
    int finder(){
        int n=par.size()-1;
        vector<int> ct(n+1,0);
        for(int i=0; i<n; i++){
            ct[findpar(i)]++;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(ct[i]) ans+=(ct[i]-1);
        }
        return ans;
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& a) {
        int n=a.size();
        DSU ds(n);
        unordered_map<int,vector<int>> row,col;
        for(int i=0; i<n; i++){
            row[a[i][0]].push_back(i);
            col[a[i][1]].push_back(i);
        }
        for(auto &e:row){
            if(e.second.size()>1){
                for(int i=0; i<e.second.size()-1; i++) ds.unite(e.second[i],e.second[i+1]);
            }
        }
        for(auto &e:col){
            if(e.second.size()>1){
                for(int i=0; i<e.second.size()-1; i++) ds.unite(e.second[i],e.second[i+1]);
            }
        }
        return ds.finder();
    }
};