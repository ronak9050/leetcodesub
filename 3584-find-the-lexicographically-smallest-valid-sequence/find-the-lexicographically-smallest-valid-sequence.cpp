class Solution {
public:
    vector<int> validSequence(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> pos(26);
        for(int i=0; i<n; i++) pos[s[i]-'a'].push_back(i);
        vector<int> mx(m+1,n+1);
        int j=m-1;
        for(int i=n-1; i>=0; i--){
            if(j<0) break;
            if(s[i]==t[j]) {
                mx[j]=i;
                j--;
            }
        }
        for(;j>=0; j--) mx[j]=-1;
        vector<int> ans;
        int mn=-1;
        for(int i=0; i<m; i++){
            auto it=upper_bound(pos[t[i]-'a'].begin(),pos[t[i]-'a'].end(),mn);
            if(it!=pos[t[i]-'a'].end() && *it==mn+1){
                ans.push_back(mn+1);
                mn++;
            }
            else if(mn+1<mx[i+1]){
                mn++;
                ans.push_back(mn);
                for(int k=i+1; k<m; k++){
                    auto it=upper_bound(pos[t[k]-'a'].begin(),pos[t[k]-'a'].end(),mn);
                    ans.push_back(*it);
                    mn=*it;
                }
                break;
            }
            else{
                if(it==pos[t[i]-'a'].end()) return {};
                else{
                    ans.push_back(*it);
                    mn=*it;
                }
            }
        }

        if(ans.size()==m) return ans;
        return {};
    }
};