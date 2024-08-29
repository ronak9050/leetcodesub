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
            findpar(i);
            ct[par[i]]++;
            cout<<par[i]<<" ";
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
        // for(int i=0;  i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(a[i][0]==a[j][0] || a[i][1]==a[j][1]) ds.unite(i,j);
        //     }
        // }
        vector<vector<int>> row(1e4+1),col(1e4+1);
        for(int i=0; i<n; i++){
            row[a[i][0]].push_back(i);
            col[a[i][1]].push_back(i);
        }
        for(int i=0; i<1e4+1; i++){
            if(row[i].size()>1){
                for(int j=0; j<row[i].size()-1; j++){
                    ds.unite(row[i][j],row[i][j+1]);
                }
            }
            if(col[i].size()>1){
                for(int j=0; j<col[i].size()-1; j++){
                    ds.unite(col[i][j],col[i][j+1]);
                }
            }
        }
        return ds.finder();
    }
};