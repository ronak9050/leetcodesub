class Solution {
public:
    vector<vector<int>> moves={{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(int i,int j,vector<vector<int>>&a,vector<vector<int>>&b,vector<vector<int>>&vis){
        vis[i][j]=1;
        int n=a.size(),m=a[0].size(),ans=1;
        if(!a[i][j]) ans=0;
        for(auto &e:moves){
            int x=i+e[0],y=j+e[1];
            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && b[x][y]) ans&=dfs(x,y,a,b,vis);
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
                if(!vis[i][j] && b[i][j]) {
                    int cur=dfs(i,j,a,b,vis);
                    // cout<<i<<" "<<j<<" "<<cur<<endl;
                    ans+=cur;
                }
            }
        }
        return ans;
    }
};