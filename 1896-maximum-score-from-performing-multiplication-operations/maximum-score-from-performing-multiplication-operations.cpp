class Solution {
public:
    int func(int ind,int i,int j,vector<int>&a,vector<int> &mul,map<vector<int>,int>&mp){
        int m=mul.size();
        if(ind>=m) return 0;
        if(mp.find({ind,i,j})!=mp.end()) return mp[{ind,i,j}];
        int ans=max(mul[ind]*a[j]+func(ind+1,i,j-1,a,mul,mp),mul[ind]*a[i]+func(ind+1,i+1,j,a,mul,mp));
        return mp[{ind,i,j}]=ans;
    }
    int maximumScore(vector<int>& a, vector<int>& mul) {
        map<vector<int>,int> mp;
        int n=a.size();
        return func(0,0,n-1,a,mul,mp);
    }
};