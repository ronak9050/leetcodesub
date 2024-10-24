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

    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        vector<int> par(n);
        for(int i=0; i<n; i++) par[i]=i;
        map<string,int> mp;
        for(int i=0; i<n; i++){
            for(int j=1; j<acc[i].size(); j++){
                if(mp.find(acc[i][j])!=mp.end()){
                    unite(i,mp[acc[i][j]],par);
                }
                else mp[acc[i][j]]=i;
            }
        }
        
        map<int,vector<string>> cur;
        map<string,bool> ump;
        for(int i=0; i<n; i++){
            findpar(i,par);
            if(cur[par[i]].size()==0) cur[par[i]].push_back(acc[i][0]);
            for(int j=1; j<acc[i].size(); j++){
                if(!ump[acc[i][j]]) {
                    cur[par[i]].push_back(acc[i][j]);
                    ump[acc[i][j]]=1;
                }
            }
        }

        vector<vector<string>> ans;
        for(auto &e:cur){
            sort(e.second.begin()+1,e.second.end());
            ans.push_back(e.second);
        }
        return ans;
    }
};