class Solution {
public:
    bool canArrange(vector<int>& a, int k) {
        unordered_map<int,int> mp;
        for(auto e:a) mp[(e%k+k)%k]++;
        if(mp[0]%2) return 0;
        for(auto &e:mp){
            if(e.first!=0){
                if((e.second!=mp[k-e.first])) return 0;
            }
        }
        return 1;
    }
};