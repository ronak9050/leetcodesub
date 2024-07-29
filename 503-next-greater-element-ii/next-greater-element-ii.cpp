class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n=a.size();
        vector<int> nge(n,-1);
        stack<int>st;
        for(int i=0; i<2*n; i++){
            while(st.size() && a[st.top()]<a[i%n]){
                nge[st.top()]=i%n;
                st.pop();
            }
            st.push(i%n);
        }
        for(int i=0; i<n; i++){
            if(nge[i]!=-1) nge[i]=a[nge[i]];
        }
        return nge;
    }
};