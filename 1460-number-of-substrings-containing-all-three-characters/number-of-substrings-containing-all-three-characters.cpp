class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),i=0,j=0,ans=0;
        vector<int> ct(3,0);
        while(i<n){
            ct[s[i]-'a']++;
            if(ct[0]&&ct[1]&&ct[2]){
                int ct1=n-i,ct2=0;
                while(ct[0]&&ct[1]&&ct[2]){
                    ct[s[j]-'a']--;
                    ct2++;
                    j++;
                }
                ans+=ct1*ct2;
            }
            i++;
        }
        return ans;
    }
};