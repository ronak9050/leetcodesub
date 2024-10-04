class Solution {
public:
    int func(string &s){
        int n=s.size(),ans=0,ct=0,cur=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                ct++;
                cur++;
            }
            else{
                if(ct){
                    ct--;
                    cur++;
                }
                else{
                    ans=max(ans,cur);
                    cur=0;
                    ct=0;
                }
            }
        }
        int i=n-1;
        while(ct){
            if(s[i]=='(') ct--;
            else ct++;
            cur--;
            i--;
        }
        ans=max(ans,cur);
        return ans;
    }

    int longestValidParentheses(string s) {
        int ans=func(s);
        cout<<s<<endl;
        reverse(s.begin(),s.end());
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') s[i]=')';
            else s[i]='(';
        }
        cout<<s<<endl;
        ans=max(ans,func(s));
        return ans;
    }
};