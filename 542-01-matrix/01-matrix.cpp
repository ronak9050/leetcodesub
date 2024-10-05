class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j]) a[i][j]=-1;
                else q.push({i,j});
            }
        }
        vector<vector<int>> moves = {{0,1},{0,-1},{-1,0},{1,0}};
        while(q.size()){
            auto it=q.front();
            q.pop();
            int x=it.first,y=it.second;
            for(auto &e:moves){
                int i=x+e[0],j=y+e[1];
                if(i<n && j<m && i>=0 && j>=0 && a[i][j]==-1){
                    a[i][j]=a[x][y]+1;
                    q.push({i,j});
                } 
            }
        }
        return a;
    }
};