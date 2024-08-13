class Solution {
public:
    int minimumLength(string s) {
        vector<int> ct(26,0);
        for(auto &e:s) ct[e-'a']++;
        int ans=0;
        for(auto &e:ct){
            if(e%2) ans+=1;
            else if(e) ans+=2; 
        }
        return ans;
    }
};