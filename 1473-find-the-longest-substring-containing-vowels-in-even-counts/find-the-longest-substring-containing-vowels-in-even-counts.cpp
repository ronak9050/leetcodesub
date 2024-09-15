class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        unordered_map<int,vector<int>> mp;
        int cur=0;
        vector<int> pos(150,0);
        pos['a']=1;pos['e']=2;pos['i']=3;pos['o']=4;pos['u']=5;
        for(int i=0; i<n; i++){
            if(pos[s[i]]){
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