class Solution {
public:
    vector<vector<int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
    int timer=0;
    int arti=0;
    void dfs(int x,int y,int parx,int pary,vector<vector<int>>&a,vector<vector<int>>&vis,vector<vector<int>>&tin,vector<vector<int>>&low){
        vis[x][y]=1;
        int n=a.size(),m=a[0].size();
        low[x][y]=tin[x][y]=timer;
        timer++;
        int child=0;
        for(auto &e:moves){
            int i=x+e[0],j=y+e[1];
            if(i==parx && j==pary) continue;
            if(i>=0 && j>=0 && i<n && j<m && a[i][j]){
                if(vis[i][j]==0){
                    dfs(i,j,x,y,a,vis,tin,low);
                    low[x][y]=min(low[i][j],low[x][y]);
                    if(low[i][j]>=tin[x][y] && parx!=-1 && pary!=-1) arti++;
                    child++;
                }
                else{
                    low[x][y]=min(low[i][j],low[x][y]);
                }
            }
        }
        if(child>1 && parx==-1 && pary==-1) arti++;
    }
    int minDays(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int ct=0,f=0;
        vector<vector<int>> vis(n,vector<int>(m)),tin(n,vector<int>(m,0)),low(n,vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] && vis[i][j]==0){
                    dfs(i,j,-1,-1,a,vis,tin,low);
                    f++;
                }
                if(a[i][j]) ct++;
            }
        }
        if(f>1) return 0;
        if(ct>2) return arti>0? 1:2;
        return ct;
    }
};