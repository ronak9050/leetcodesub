class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        map<int,vector<int>> mp;
        for(int i=0; i<a.size(); i++) mp[a[i]].push_back(i);
        int rank=1;
        for(auto &e:mp){
            for(auto f:e.second) a[f]=rank;
            rank++;
        }
        return a;
    }
};