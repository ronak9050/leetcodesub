class Solution {
public:
    bool canArrange(vector<int>& a, int k) {
        vector<int> mp(k,0);
        for(auto e:a) mp[(e%k+k)%k]++;
        if(mp[0]%2) return 0;
        for(int i=1; i<=k/2; i++){
            if(mp[i]!=mp[k-i]) return 0;
        }
        return 1;
    }
};