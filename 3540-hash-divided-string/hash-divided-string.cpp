class Solution {
public:
    string stringHash(string s, int k) {
        string ans;
        int n=s.size();
        int i=0;
        while(i<n){
            int cur=0;
            for(int j=0; j<k; j++){
                cur+=(s[i+j]-'a');
            }
            ans.push_back('a'+cur%26);
            i+=k;
        }
        return ans;
    }
};