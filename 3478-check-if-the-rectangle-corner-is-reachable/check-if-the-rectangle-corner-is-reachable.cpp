class Solution {
public:
    void check(int &l,int &r,int &u,int &d,int x,int y,int x1,int y1,int r1){
        if(x1+r1>=x) r=1;
        if(x1-r1<=0) l=1;
        if(y1+r1>=y) u=1;
        if(y1-r1<=0) d=1;

    }
    bool canReachCorner(int x, int y, vector<vector<int>>& c) {
        int n=c.size();
        sort(c.begin(),c.end());
        for(int i=0; i<n; i++){
            vector<vector<int>> cur={c[i],c[i],c[i],c[i]}; //LRUD
            int l=0,r=0,d=0,u=0;
            check(l,r,u,d,x,y,c[i][0],c[i][1],c[i][2]);
            for(int j=i+1; j<n; j++){
                // if(i==j) continue;
                for(int k=0; k<4; k++){
                    double dis=sqrtl((cur[k][0]-c[j][0])*1ll*(cur[k][0]-c[j][0])+(cur[k][1]-c[j][1])*1ll*(cur[k][1]-c[j][1]));
                    double reff = c[j][2]+cur[k][2];
                    if(dis<=reff){
                        check(l,r,u,d,x,y,c[j][0],c[j][1],c[j][2]);
                        if(cur[k][0]-cur[k][2]>c[j][0]-c[j][2]) cur[0]=c[j];
                        if(cur[k][0]+cur[k][2]<c[j][0]+c[j][2]) cur[1]=c[j];
                        if(cur[k][1]+cur[k][2]<c[j][1]+c[j][2]) cur[2]=c[j];
                        if(cur[k][1]-cur[k][2]>c[j][1]-c[j][2]) cur[3]=c[j];
                    }
                }
            }
            if((l&r)|(u&d)|(l&d)|(u*r)) return 0;
        }
        return 1;
    }
};