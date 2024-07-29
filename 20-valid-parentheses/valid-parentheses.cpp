class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                if(st.empty()) return false;
                char tp=st.top();
                if((s[i]==')' && tp=='(')|| (s[i]=='}' && tp=='{') || (s[i]==']' && tp=='[')) st.pop();

                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};