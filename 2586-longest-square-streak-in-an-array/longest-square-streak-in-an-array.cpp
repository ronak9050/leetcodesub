class Solution {
public:
    int mx=1;
    int func(long cur,vector<int>&ct,vector<int> &ans){
        if(cur>1e5 || !ct[cur]) return 0;
        if(ans[cur]!=-1) return ans[cur];
        ans[cur]=1+func(cur*1ll*cur,ct,ans);
        mx=max(mx,ans[cur]);
        return ans[cur];
    }

    int longestSquareStreak(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<int> ct(1e5+1,0),ans(1e5+1,-1);
        for(auto e:a) ct[e]++;
        for(auto e:a){
            func(e,ct,ans);
        }
        return mx>1? mx:-1;
    }
};