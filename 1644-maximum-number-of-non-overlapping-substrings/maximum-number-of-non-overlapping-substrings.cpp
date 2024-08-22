class Solution {
public:
    pair<int,int> func(int ind,vector<int>&st,vector<int>&end,vector<int>&vis,vector<vector<int>>&g){
        int a=st[ind],b=end[ind];
        vis[ind]=1;
        for(auto &e:g[ind]){
            if(!vis[e]){
                auto cur=func(e,st,end,vis,g);
                a=min(a,cur.first);
                b=max(b,cur.second);
            }
        }
        return {a,b};
    }

    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second) a.first>b.first;
        return a.second<b.second;
    }
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> st(26,-1),end(26,-1);
        for(int i=0; i<n; i++){
            if(st[s[i]-'a']==-1) st[s[i]-'a']=i;
            end[s[i]-'a']=i;
        }
        vector<vector<int>> g(26);
        for(int j=0; j<26; j++){
            if(st[j]!=-1){
                vector<int> here(26,0);
                for(int i=st[j]+1; i<end[j]; i++) here[s[i]-'a']=1;
                for(int i=0; i<26; i++) {
                    if(here[i]) g[j].push_back(i);
                }
            }
        }

        vector<pair<int,int>> pos;
        for(int i=0; i<26; i++){
            if(st[i]!=-1){
                vector<int> vis(26,0);
                pos.push_back(func(i,st,end,vis,g));
            }
        }

        sort(pos.begin(),pos.end(),cmp);
        vector<string> ret;
        int last=-1;
        for(int i=0; i<pos.size(); i++){
            if(pos[i].first>last){
                last=pos[i].second;
                string tmp;
                for(int j=pos[i].first; j<=pos[i].second; j++){
                    tmp.push_back(s[j]);
                }
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};