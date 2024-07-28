class Solution {
public:

    int secondMinimum(int n, vector<vector<int>>& edges, int t, int c) {
        vector<vector<int>> g(n+1);
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> vis(n+1,0),path(n+1,-1);
        queue<pair<int,int>> q;
        q.push({1,0});
        int last=0,ct=0;
        while(!q.empty()){
            int  cur=q.front().first;
            int time=q.front().second;
            q.pop();
            
            if(cur==n && time>path[cur] && vis[cur]==1) return time;
            if(path[cur]>=time) continue;
            vis[cur]++;
            path[cur]=time;
            
            for(auto &e:g[cur]){
                if(vis[e]>=2) continue;
                int pt;
                if((time/c)&1) pt=(time/c+1)*c+t;
                else pt=time+t;
                q.push({e,pt});
            }
        }
        return -1;
    }
};