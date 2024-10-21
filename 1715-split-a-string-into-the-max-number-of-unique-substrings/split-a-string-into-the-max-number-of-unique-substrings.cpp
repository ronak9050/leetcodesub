class Solution {
public:
    int func(int ind,string &s,set<string> &st,string cur){
        int n=s.size();
        if(ind>=n) {
            int ans=st.size();
            if(cur.size()){
                st.insert(cur);
                ans=st.size();
                st.erase(cur);
            }
            return ans;
        }
        int ans=0;
        if(st.find(cur)==st.end()){
            st.insert(cur);
            string tmp;
            tmp.push_back(s[ind]);
            ans=func(ind+1,s,st,tmp);
            st.erase(cur);
        }
        cur.push_back(s[ind]);
        ans=max(ans,func(ind+1,s,st,cur));
        return ans;
    }

    int maxUniqueSplit(string s) {
        set<string> st;
        return func(0,s,st,"")-1;
    }
};