class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
        int dir=1;
        int ans=0,x=0,y=0;
        map<pair<int,int>,int> mp;
        for(auto &e:obstacles){
            mp[{e[0],e[1]}]=1;
        }
        for(auto &e:commands){
            if(e==-1) dir=(dir-1+4)%4;
            else if(e==-2) dir=(dir+1)%4;
            else{
                for(int i=0; i<e; i++){
                    if(mp.find({x+moves[dir][0],y+moves[dir][1]})==mp.end()){
                        x+=moves[dir][0];
                        y+=moves[dir][1];
                    }
                    else break;
                }
            }
            ans=max(ans,x*x+y*y);
        }
        return ans;
    }
};