class Solution {
public:
    int minGroups(vector<vector<int>>& a) {
        int mx=0;
        for(auto &e:a) mx=max(mx,e[1]);
        vector<int> ct(mx+2,0);
        for(auto &e:a){
            ct[e[0]]++;
            ct[e[1]+1]--;
        }
        int ans=0,cur=0;
        for(int i=1; i<=mx; i++){
            cur+=ct[i];
            ans=max(ans,cur);
        }
        return ans;
    }
};