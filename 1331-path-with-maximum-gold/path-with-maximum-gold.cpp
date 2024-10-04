class Solution {
public:
    vector<vector<int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};

    int func(int i,int j,vector<vector<int>>&a,vector<vector<int>>&vis){
        int n=a.size(),m=a[0].size(),ans=0;
        vis[i][j]=1;
        int tmp=a[i][j];
        a[i][j]=0;
        for(auto &e:moves){
            int x=i+e[0],y=j+e[1];
            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && a[x][y]){
                ans=max(ans,func(x,y,a,vis));
            }
        }
        vis[i][j]=0;
        a[i][j]=tmp;
        return ans+a[i][j];
    }

    int getMaximumGold(vector<vector<int>>& a) {
        int ans=0;
        int n=a.size(),m=a[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)); 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j]){
                    ans=max(ans,func(i,j,a,vis));
                }
            }
        }
        return ans;
    }
};