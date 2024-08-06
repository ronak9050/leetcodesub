class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        int m=q.size();
        vector<int> ans(m);
        int cur=n-1;
        set<pair<int,int>> s;
        for(int i=0; i<m; i++){
            int st=q[i][0],end=q[i][1];
            auto it=s.upper_bound({st,end});
            if(it!=s.end()){
                if(it->second>=end || (it->first<=end && it->second>=st)){
                    while(it!=s.end() && it->first<=end && it->second>=st){
                        cur=cur-1+(it->first-it->second);
                        s.erase(it);
                        it=s.upper_bound({st,0});
                    }
                    cur=cur+1-(end-st);
                    s.insert({end,st});
                }
            }
            else{
                s.insert({end,st});
                cur=cur+1-(end-st);
            }
            ans[i]=cur;
        }
        return ans;
        
    }
};