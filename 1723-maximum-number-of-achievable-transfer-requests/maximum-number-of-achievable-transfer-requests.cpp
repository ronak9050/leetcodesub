class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& req) {
        
        int ans=0,m=req.size();
        for(int i=0; i<(1<<m); i++){
            int bt=__builtin_popcountll(i);
            if(bt<=ans) continue;
            vector<int> ct(n,0);
            for(int j=0; j<m; j++){
                if(i&(1<<j)){
                    ct[req[j][0]]--;
                    ct[req[j][1]]++;
                }
            }
            int f=1;
            for(int j=0; j<n; j++) if(ct[j]) f=0;
            if(f) ans=bt;
        }
        return ans;
    }
};