class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& b, vector<int>& a) {
        stack<int> st;
        int n=a.size();
        vector<int> nge(n,-1);
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            while(st.size() && a[st.top()]<a[i]){
                nge[st.top()]=i;
                st.pop();
            }
            st.push(i);
            mp[a[i]]=i;
        }
        vector<int> ans(b.size());
        for(int i=0; i<b.size(); i++){
            int ind=nge[mp[b[i]]];
            if(ind!=-1) ind=a[ind];
            ans[i]=ind;
        }
        return ans;
    }
};