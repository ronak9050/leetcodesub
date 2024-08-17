#define ll long long

class Solution {
public:
    
    ll func(int ct,int rem,set<vector<ll>> st,vector<int> &row,vector<int> &col){
        if(rem==0) return 0;
        if(ct==0 || st.empty()) return -1e15;
        
        ll ans=-1e15;
        auto it=st.end();
        it--;
        while(st.size() && (row[it->at(1)] || col[it->at(2)])){
            st.erase(it);
            it=st.end();
            if(st.size()) it--;
            else break;
        }
        if(st.size()==0) return -1e15;
        it=st.end();
        it--;
        auto cur=*it;
        st.erase(it);
        
        ans=func(ct-1,rem,st,row,col);
        row[cur[1]]=1;
        col[cur[2]]=1;
        ans=max(ans,cur[0]+func(ct-1,rem-1,st,row,col));
        row[cur[1]]=0;
        col[cur[2]]=0;
        return ans;
    }
        
    long long maximumValueSum(vector<vector<int>>& a) {
        ll n=a.size(),m=a[0].size();
        set<vector<ll>> st;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                st.insert({a[i][j],i,j});
            }
        }
        vector<int> row(n,0),col(m,0);
        while(st.size()>601){
            st.erase(st.begin());
        }
        ll ans=func(6,3,st,row,col);
        return ans;
    }
};