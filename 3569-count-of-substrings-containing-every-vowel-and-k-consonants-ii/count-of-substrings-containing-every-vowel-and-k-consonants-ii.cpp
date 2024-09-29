#define ll long long

class Solution {
public:
    vector<int> mp;
    long long countOfSubstrings(string s, int req) {
        mp.resize(26,0);
        mp[0]=1;mp[4]=2;mp[8]=3;mp[14]=4;mp[20]=5;
        ll n=s.size(),ans=0,ct=0,last=-1;

        vector<int> cmin(n,-1),cmax(n,-1),pos,vmax(n,-1);
        vector<vector<int>> prevpos(6);
    
        for(int i=0; i<n; i++){
            if(mp[s[i]-'a']){
                prevpos[mp[s[i]-'a']].push_back(i);
            }
            int cur=n;
            for(int j=1; j<6; j++){
                if(prevpos[j].size()) cur=min(cur,prevpos[j].back());
                else cur=-1;
            }
            vmax[i]=cur;
        }

        if(req){

            for(int i=0; i<n; i++){
                if(!mp[s[i]-'a']){
                    pos.push_back(i);
                    if(pos.size()>=req) cmax[i]=pos[pos.size()-req];
                    if(pos.size()>req) cmin[i]=pos[pos.size()-req-1];     
                }
                else{
                    if(i) cmax[i]=cmax[i-1];
                    if(i) cmin[i]=cmin[i-1];
                }
            }
            for(int i=0; i<n; i++){
                
                if(min(vmax[i],cmax[i])>cmin[i]) ans=ans+min(vmax[i],cmax[i])-cmin[i];
            }
            return ans;
        }
        else{
            for(int i=0; i<n; i++){
                if(!mp[s[i]-'a']) last=i;
                cmin[i]=last;
            }
            for(int i=0; i<n; i++) {
                cout<<cmin[i]<<" "<<vmax[i]<<endl;
                if(cmin[i]<vmax[i]) ans=ans+vmax[i]-cmin[i];
            }
        }
        return ans;
    }
};