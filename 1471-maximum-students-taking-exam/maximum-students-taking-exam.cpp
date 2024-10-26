class Solution {
public:
    int dp[8][8][1<<8][1<<8];

    bool check(char s,int y,int m,int pre,int cur){
        if(s=='#') return 0;
        if(y){
            if(pre&(1<<(y-1))) return 0;
            if(cur&(1<<(y-1))) return 0;
        }
        if(y<m-1){
            if(pre&(1<<(y+1))) return 0;
        }
        return 1;
    }


    int func(int x,int y,int pre,int cur,vector<vector<char>> &s){
        int n=s.size(),m=s[0].size();
        if(y==m) return func(x+1,0,cur,0,s);
        if(x==n) return 0;
        if(dp[x][y][pre][cur]!=-1) return dp[x][y][pre][cur];
        int ans=func(x,y+1,pre,(cur&(1<<y))? cur^(1<<y):cur,s);
        if(check(s[x][y],y,m,pre,cur)) ans=max(ans,1+func(x,y+1,pre,cur|(1<<y),s));

        return dp[x][y][pre][cur]=ans;
    }

    int maxStudents(vector<vector<char>>& s) {
        memset(dp,-1,sizeof(dp));
        return func(0,0,0,0,s);
    }
};