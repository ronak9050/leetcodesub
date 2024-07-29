class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n=a.size();
        vector<int> left(n,-1),right(n,n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(st.size() && a[st.top()]>a[i]){
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(st.size() && a[st.top()]>a[i]){
                left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans,a[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};