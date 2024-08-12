class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        string ans;
        for(int i=0; i<n; i++){
            if(s[i]-'a'<26 && s[i]-'a'>=0) ans.push_back(s[i]);
            else{
                if(ans.size()) ans.pop_back();
            }
        }
        
        return ans;
    }
};