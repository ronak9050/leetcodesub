class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size(),cur=0,ans=0;
        vector<int> mp(65,-1),pos(150,0);
        pos['a']=1;pos['e']=2;pos['i']=3;pos['o']=4;pos['u']=5;

        for(int i=0; i<n; i++){
            if(pos[s[i]]){
                cur=cur^(1<<(pos[s[i]]));
            }
            if(cur==0) ans=max(ans,i+1);
            else if(mp[cur]==-1) mp[cur]=i;
            else ans=max(ans,i-mp[cur]);
        }

        return ans;
    }
};