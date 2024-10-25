class Solution {
public:
    int dp[5][5][7][7][64][64];

    int check1(int y,int m,int ext,int inr){
        int ans=120;
        if(ext&(1<<y)) ans-=10;
        if(inr&(1<<y)) ans-=60;
        if(y){
            if(ext&(1<<(y-1))) ans-=10;
            if(inr&(1<<(y-1))) ans-=60;
        }
        return ans;
    }

    int check2(int y,int m,int ext,int inr){
        int ans=40;
        if(ext&(1<<y)) ans+=40;
        if(inr&(1<<y)) ans-=10;
        if(y){
            if(ext&(1<<(y-1))) ans+=40;
            if(inr&(1<<(y-1))) ans-=10;
        }
        return ans;
    }


    int func(int x,int y,int n,int m,int ict,int exct,int ext,int inr){
        if(x==n) return 0;
        if(y==m) return func(x+1,0,n,m,ict,exct,ext,inr);

        if(dp[x][y][ict][exct][ext][inr]!=-1) return dp[x][y][ict][exct][ext][inr];

        int ans=func(x,y+1,n,m,ict,exct,((ext>>y)&1)? ext^(1<<y):ext,((inr>>y)&1)? inr^(1<<y):inr);
        if(ict){
            ans=max(ans,check1(y,m,ext,inr)+func(x,y+1,n,m,ict-1,exct,((ext>>y)&1)? ext^(1<<y):ext,inr|(1<<y)));
        }
        if(exct){
            ans=max(ans,check2(y,m,ext,inr)+func(x,y+1,n,m,ict,exct-1,ext|(1<<y),((inr>>y)&1)? inr^(1<<y):inr));
        }

        return dp[x][y][ict][exct][ext][inr]=ans;
    }

    int getMaxGridHappiness(int m, int n, int ict, int exct) {
        memset(dp,-1,sizeof(dp));
        return func(0,0,n,m,ict,exct,0,0);
    }
};