class Solution {
public:
    vector<vector<int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};

    int maximumSafenessFactor(vector<vector<int>>& a) {
        int n=a.size();
        // if(a[0][0] || a[n-1][n-1]) return 0;
        vector<vector<int>> fac(n,vector<int>(n,1e9));
        queue<vector<int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j]) {
                    q.push({i,j,0});
                    fac[i][j]=0;
                }
            }
        }

        while(q.size()){
            auto it=q.front();
            q.pop();
            int i=it[0],j=it[1],t=it[2];
            for(auto &e:moves){
                int x=i+e[0],y=j+e[1];
                if(x>=0 && y>=0 && x<n && y<n && t+1<fac[x][y]){
                    fac[x][y]=t+1;
                    q.push({x,y,t+1});
                }
            }
        }

        int l=0,h=n-1,ans;
        while(l<=h){
            int mid=l+(h-l)/2;  
            vector<vector<int>> pos(n,vector<int>(n,0)),vis(n,vector<int>(n,0));
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++) if(fac[i][j]>=mid) pos[i][j]=1;
            }
            queue<pair<int,int>> q;
            if(pos[0][0]) q.push({0,0});
            vis[0][0]=1;
            while(q.size()){
                auto it=q.front();
                q.pop();
                int x=it.first,y=it.second;
                for(auto &e:moves){
                    int i=x+e[0],j=y+e[1];
                    if(i<n && j<n && i>=0 && j>=0 && !vis[i][j] && pos[i][j]){
                        vis[i][j]=1;
                        q.push({i,j});
                    }
                }
            }

            if(vis[n-1][n-1]){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};