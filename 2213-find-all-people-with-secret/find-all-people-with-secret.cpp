class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int start) {
        vector<vector<vector<int>>> g(n);
        for(auto &e:meet){
            g[e[0]].push_back({e[2],e[1]});
            g[e[1]].push_back({e[2],e[0]});
        }
        for(int i=0; i<n; i++) sort(g[i].begin(),g[i].end());
        set<int> st;
        vector<int> vis(n,INT_MAX);
        queue<vector<int>> q;
        q.push({0,0});
        q.push({start,0});
        while(q.size()){
            auto it=q.front();
            q.pop();
            int cur=it[0],tcur=it[1];
            if(vis[cur]<=tcur) continue;
            vis[cur]=tcur;
            st.insert(cur);
            for(auto &e:g[cur]){
                int v=e[1],t=e[0];
                if(t>=tcur && vis[v]>t) q.push({v,t});
            }
        }
        vector<int> ans;
        for(auto &e:st) ans.push_back(e);
        return ans;
    }
};