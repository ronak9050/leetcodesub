class Solution {
public:
    vector<vector<int>> moves={{0,1},{0,-1},{1,0},{-1,0}};
    bool check(int x,int y,int ptr,string &s,vector<vector<char>>&a,vector<vector<int>>&vis){
        if(ptr==s.size()) return 1;
        int n=a.size(),m=a[0].size();
        vis[x][y]=1;
        for(auto &e:moves){
            int i=x+e[0],j=y+e[1];
            if(i<n && j<m && i>=0 && j>=0 && !vis[i][j] && s[ptr]==a[i][j]){
                if(ptr+1==s.size()) return 1;
                if(check(i,j,ptr+1,s,a,vis)) return 1;
            }
        }
        vis[x][y]=0;
        return 0;
    }

    bool exist(vector<vector<char>>& a, string s) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(s[0]==a[i][j]){
                    if(check(i,j,1,s,a,vis)) return 1;
                }
            }
        }
        return 0;
    }
};