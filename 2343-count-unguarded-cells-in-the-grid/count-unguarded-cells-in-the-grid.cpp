class Solution {
public:
    void func(int m,int n,int x,int y,vector<vector<int>>&vis,map<pair<int,int>,bool> &mp){
        for(int i=x-1; i>=0; i--){
            if(mp[{i,y}]) break;
            vis[i][y]=1;
        }
        for(int i=x+1; i<m; i++){
            if(mp[{i,y}]) break;
            vis[i][y]=1;
        }
        for(int i=y-1; i>=0; i--){
            if(mp[{x,i}]) break;
            vis[x][i]=1;
        }
        for(int i=y+1; i<n; i++){
            if(mp[{x,i}]) break;
            vis[x][i]=1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        map<pair<int,int>,bool> mp;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(auto &e:g) {
            mp[{e[0],e[1]}]=1;
            vis[e[0]][e[1]]=1;
        }
        for(auto &e:w) {
            mp[{e[0],e[1]}]=1;
            vis[e[0]][e[1]]=1;
        }
        for(auto &e:g){
            func(m,n,e[0],e[1],vis,mp);
        }

        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) if(!vis[i][j]) ans++;
        }
        return ans;
    }
};