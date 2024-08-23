class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> g(n);
        vector<int> indeg(n,0);
        for(auto &e:pre) {
            g[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }
        vector<int> vis(n,0);
        queue<int> q;
        for(int i=0; i<n; i++) if(!indeg[i]) q.push(i);
        while(q.size()){
            int cur=q.front();
            q.pop();
            vis[cur]=1;
            for(auto &e:g[cur]){
                indeg[e]--;
                if(!indeg[e]) q.push(e);
            }
        }
        for(int i=0; i<n; i++) if(!vis[i]) return 0;
        return 1;
    }
};