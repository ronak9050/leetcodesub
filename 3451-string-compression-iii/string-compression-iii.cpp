class Solution {
public:
    string compressedString(string s) {
        string ans;
        char c=s[0];
        int ct=1;
        for(int i=1; i<s.size(); i++){
            if(s[i]==s[i-1] && ct<9) ct++;
            else{
                ans.push_back(ct+'0');
                ans.push_back(c);
                c=s[i];
                ct=1;
            }
        }
        ans.push_back(ct+'0');
        ans.push_back(c);
        return ans;
    }
};