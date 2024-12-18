class Solution {
public:

    int bfs(vector<vector<int>>&g){
        int n=g.size();
        if(g.size()==1 && g[0].size()==0) return 0;
        map<pair<int,int>,bool> mp;
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            q.push({i,1<<i});
            mp[{i,1<<i}]=1;
        }

        int lvl=0;
        int end=(1<<n)-1;
        while(q.size()){
            int sz=q.size();
            for(int i=0; i<sz; i++){
                auto it=q.front();
                q.pop();
                int cur=it.first,mask=it.second;
                for(auto e:g[cur]){
                    if(!mp[{e,mask|(1<<e)}]){
                        if((mask|(1<<e))==end) return lvl+1;
                        mp[{e,mask|(1<<e)}]=1;
                        q.push({e,mask|(1<<e)});
                    }
                }
            }
            lvl++;
        }
        return lvl;
    }


    int shortestPathLength(vector<vector<int>>& graph) {
        return bfs(graph);
    }
};