class Solution {
public:
    vector<vector<int>> moves={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i,int j,vector<vector<int>>&a,vector<vector<int>>&vis){
        vis[i][j]=1;
        int n=a.size(),m=a[0].size();
        for(auto &e:moves){
            int x=i+e[0],y=j+e[1];
            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && a[x][y]) dfs(x,y,a,vis);
        }
    }

    int dfs2(int i,int j,vector<vector<int>>&b,vector<vector<int>>&vis,vector<vector<int>>&vis2){
        vis2[i][j]=1;
        int ans=1,n=b.size(),m=b[0].size();
        if(!vis[i][j]) {
            // cout<<i<<" "<<j<<endl;
            ans=0;
        }
        for(auto &e:moves){
            int x=i+e[0],y=j+e[1];
            if(x>=0 && y>=0 && x<n && y<m && !vis2[x][y] && b[x][y]) ans&=dfs2(x,y,b,vis,vis2);
        }
        return ans;
    }

    int countSubIslands(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> vis2(n,vector<int>(m,0));
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && a[i][j]) dfs(i,j,a,vis);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis2[i][j] && b[i][j]) {
                    int cur=dfs2(i,j,b,vis,vis2);
                    // cout<<i<<" "<<j<<" "<<cur<<endl;
                    ans+=cur;
                }
            }
        }
        return ans;
    }
};