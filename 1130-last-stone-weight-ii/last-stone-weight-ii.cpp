class Solution {
public:
    int func(int i,int sum,vector<int>&a,map<pair<int,int>,int> &mp){
        int n=a.size();
        if(i>=n) return abs(sum);
        if(mp.find({i,sum})!=mp.end()) return mp[{i,sum}];
        int ans=min(func(i+1,sum-a[i],a,mp),func(i+1,sum+a[i],a,mp));
        return mp[{i,sum}]=ans;
    }

    int lastStoneWeightII(vector<int>& a) {
        int n=a.size();
        map<pair<int,int>,int> mp;
        return func(0,0,a,mp);
    }
};