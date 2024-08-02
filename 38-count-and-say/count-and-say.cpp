class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1);
        int ct=0;
        char c=s[0];
        string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i]==c) ct++;
            else{
                string num=to_string(ct);
                for(auto &e:num) ans.push_back(e);
                ans.push_back(c);
                ct=1;
                c=s[i];
            }
        }
        string num=to_string(ct);
        for(auto &e:num) ans.push_back(e);
        ans.push_back(c);
        return ans;
    }
};