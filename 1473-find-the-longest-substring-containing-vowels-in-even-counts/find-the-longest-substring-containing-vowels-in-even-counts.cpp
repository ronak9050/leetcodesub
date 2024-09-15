class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        map<int,vector<int>> mp;
        int cur=0;
        map<char,int> pos = {{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}};
        for(int i=0; i<n; i++){
            if(pos.find(s[i])!=pos.end()){
                cur=cur^(1<<(pos[s[i]]));
            }
            mp[cur].push_back(i);
        }
        int ans=0;
        for(auto &e:mp){
            if(e.second.size()>1){
                ans=max(ans,e.second.back()-e.second[0]);
            }
        }
        if(mp[0].size()!=0) ans=max(ans,mp[0].back()+1);
        return ans;
    }
};