

class Solution {
public:
    int dfs(int ind,vector<vector<int>>&g,vector<int>&vis){
        int cur=0;
        vis[ind]=1;
        for(auto &e:g[ind]) {
            if(!vis[e]) cur+=dfs(e,g,vis);
        }
        return cur+1;
    }

    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> indeg(n,0);
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }
        int ans=-1,ct=0;
        vector<int> vis(n,0);
        for(int i=0; i<n; i++) {
            if(!indeg[i]){
                if(dfs(i,g,vis)==n){
                    ct++;
                    ans=i;
                }
            }
        }
        if(ct>1) ans=-1;

        return ans;
    }
};