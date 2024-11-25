class Solution {
public:

    int slidingPuzzle(vector<vector<int>>& a) {
        queue<pair<int,vector<vector<int>>>> q;
        q.push({0,a});
        map<vector<vector<int>>,bool> mp;
        mp[a]=1;
        vector<vector<int>> end={{1,2,3},{4,5,0}};
        if(a==end) return 0;
        vector<vector<int>> moves={{0,1},{0,-1},{1,0},{-1,0}};
        while(q.size()){
            auto it=q.front();
            q.pop();
            int mov=it.first;
            auto cur=it.second;

            int indi,indj;
            for(int i=0; i<2; i++){
                for(int j=0; j<3; j++) if(cur[i][j]==0) indi=i,indj=j;
            }

            for(auto &e:moves){
                int x=indi+e[0],y=indj+e[1];
                if(x>=0 && y>=0 && x<2 && y<3){
                    swap(cur[x][y],cur[indi][indj]);
                    if(cur==end) return mov+1;
                    if(!mp[cur]){
                        q.push({mov+1,cur});
                        mp[cur]=1;
                    }
                    swap(cur[x][y],cur[indi][indj]);
                }
            }

        }
        return -1;
    }
};