#define ll long long

class Solution {
public:
        
    long long maximumValueSum(vector<vector<int>>& a) {
        ll n=a.size(),m=a[0].size();
        vector<vector<ll>> pos;
        for(int i=0; i<n; i++){
            set<vector<ll>> st;
            for(int j=0; j<m; j++){
                st.insert({a[i][j],i,j});
            }
            auto it=st.end();
            it--;
            for(int j=0; j<3; j++) {
                pos.push_back(*it);
                it--;
            }
        }
        sort(pos.begin(),pos.end(),greater<vector<ll>>());
        ll ans=-1e15;
        int sz=pos.size();
        n=min(sz,1501);
        for(int i=0; i<4; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(pos[i][1]!=pos[j][1] && pos[j][1]!=pos[k][1] && pos[k][1]!=pos[i][1]){
                        if(pos[i][2]!=pos[j][2] && pos[j][2]!=pos[k][2] && pos[k][2]!=pos[i][2]){
                            ans=max(ans,pos[i][0]+pos[j][0]+pos[k][0]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};