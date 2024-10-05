class Solution {
public:
    bool func(string &s){
        int ct=0,ext=0,n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='(') ct++;
            else if(s[i]==')'){
                if(ct) ct--;
                else if(ext) ext--;
                else return 0;
            }
            else ext++;
        }
        return ct<=ext;
    }

    bool checkValidString(string s) {
        bool ans=func(s);
        reverse(s.begin(),s.end());
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') s[i]=')';
            else if(s[i]==')') s[i]='(';
        }
        ans&=func(s);
        return ans;
    }
};