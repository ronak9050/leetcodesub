class Solution {
public:
    int subarraysWithKDistinct(vector<int>& a, int k) {
        int n=a.size(),i=0,j=0,ans=0;
        vector<int> mp(n+1,0);
        unordered_set<int> st;
        while(i<n){
            if(st.size()<k){
                st.insert(a[i]);
                mp[a[i]]++;
                i++;
            }
            else{
                int ct2=1;
                while(mp[a[j]]>1){
                    ct2++;
                    mp[a[j]]--;
                    j++;
                }
                ans+=ct2;
                while(i<n && mp[a[i]]){
                    mp[a[i]]++;
                    i++;
                    while(mp[a[j]]>1){
                        ct2++;
                        mp[a[j]]--;
                        j++;
                    }
                    ans+=ct2;
                }
                st.erase(a[j]);
                mp[a[j]]--;
                j++;
            }
            
        }
        if(st.size()==k){
            int ct2=1;
            while(j<n && mp[a[j]]>1){
                mp[a[j]]--;
                j++;
                ct2++;
            }
            ans+=ct2;
        }
        return ans;
    }
};