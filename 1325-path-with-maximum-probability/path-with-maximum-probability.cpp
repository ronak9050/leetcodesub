const int M=1e4+3;
double vis[M]={0.0};
vector<vector<pair<int,double>>> g(M);

class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i=0; i<M; i++){
            vis[i]=0;
            g[i].clear();
        }
        double ans=0.0;
        vis[start]=1;
        for(int i=0; i<edges.size(); i++){
            g[edges[i][0]].push_back({edges[i][1],succProb[i]});
            g[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        queue<pair<int,double>> q;
        q.push({start,1});
        while(!q.empty()){
            int vert=q.front().first;
            double mult=q.front().second;
            q.pop();
            for(auto e:g[vert]){
                int cur_v=e.first;
                double prob=e.second;
                if(vis[cur_v]<vis[vert]*prob){
                    vis[cur_v]=vis[vert]*prob;
                    q.push({cur_v,vis[cur_v]});
                }
            }
        }
        return vis[end];
    }
};