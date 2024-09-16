class Solution {
public:
    vector<vector<int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};

    int func(int n,int m,vector<vector<int>>&a){
        deque<vector<int>> dq;
        dq.push_back({a[0][0],0,0});
        vector<vector<int>> dp(n,vector<int>(m,1e9));
        dp[0][0]=a[0][0];
        while(dq.size()){
            auto cur=dq.front();
            dq.pop_front();
            int x=cur[1],y=cur[2],t=cur[0];
            for(auto &e:moves){
                int i=x+e[0],j=y+e[1];
                if(i>=0 && j>=0 && i<n && j<m && dp[i][j]>t+a[i][j]){
                    dp[i][j]=t+a[i][j];
                    if(a[i][j]) dq.push_back({dp[i][j],i,j});
                    else dq.push_front({dp[i][j],i,j});
                }
            }
        }
        return dp[n-1][m-1];
    }

    bool findSafeWalk(vector<vector<int>>& a, int h) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)),dp(n,vector<int>(m,-1));
        int mn=func(n,m,a);
        cout<<mn<<endl;
        return mn<h;
    }
};