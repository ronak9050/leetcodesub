class Solution {
public:
    int minLengthAfterRemovals(vector<int>& a) {
        unordered_map<int,int> mp;
        int n=a.size();
        for(auto e:a) mp[e]++;
        vector<int> ct;
        for(auto &e:mp) ct.push_back(e.second);
        sort(ct.begin(),ct.end());
        if(ct.size()==1) return n;
        int sum=0;
        for(int i=0; i<ct.size()-1; i++) sum+=ct[i];
        if(ct.back()>sum) return ct.back()-sum;
        else if(n&1) return 1;
        return 0;
    }
};