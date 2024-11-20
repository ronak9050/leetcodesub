class Solution {
public:
    int search(int a,int b,int c,vector<vector<int>> &ct){
        int ai=lower_bound(ct[0].begin(),ct[0].end(),a)-ct[0].begin();
        int bi=lower_bound(ct[1].begin(),ct[1].end(),b)-ct[1].begin();
        int ci=lower_bound(ct[2].begin(),ct[2].end(),c)-ct[2].begin();
        return max({ai,bi,ci});
    }

    int takeCharacters(string s, int k) {
        int n=s.size();
        if(k==0) return 0;
        vector<vector<int>> ct(3,vector<int>(n,0));
        for(int i=0; i<n; i++){
            if(i){
                ct[0][i]=ct[0][i-1];
                ct[2][i]=ct[2][i-1];
                ct[1][i]=ct[1][i-1];
            }
            ct[s[i]-'a'][i]++;
        }

        int it=search(k,k,k,ct);
        if(it==n) return -1;
        int ans=it+1;
        vector<int> cur(3,0);
        for(int i=n-1; i>=0; i--){
            cur[s[i]-'a']++;
            if(cur[0]>=k && cur[1]>=k && cur[2]>=k){
                ans=min(ans,(n-i));
                break;
            }
            int ind=search(k-cur[0],k-cur[1],k-cur[2],ct);
            if(ind>=i) continue;
            ans=min(ans,(n-i)+ind+1);
        }
        return ans;
    }
};