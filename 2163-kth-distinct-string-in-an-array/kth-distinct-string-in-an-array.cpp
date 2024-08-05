class Solution {
public:
    string kthDistinct(vector<string>& a, int k) {
        unordered_map<string,int> mp;
        int ct=0;
        for(auto &e:a){
            mp[e]++;
        }
        for(auto &e:a){
            if(mp[e]==1){
                ct++;
                if(ct==k) return e;
            }
        }
        return "";
    }
};