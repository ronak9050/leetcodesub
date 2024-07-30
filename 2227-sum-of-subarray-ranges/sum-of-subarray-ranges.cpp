#define ll long long
class Solution {
public:
    void func(vector<int>&a,vector<int>&nge,vector<int>&pge,vector<int>&nse,vector<int>&pse){
        int n=a.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            while(st.size() && a[st.top()]<=a[i]){
                nge[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=0; i<n; i++){
            while(st.size() && a[st.top()]>=a[i]){
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(st.size() && a[st.top()]<a[i]){
                pge[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(st.size() && a[st.top()]>a[i]){
                pse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

    }
    long long subArrayRanges(vector<int>& a) {
        ll ans=0,n=a.size();
        vector<int> nge(n,n),pge(n,-1),nse(n,n),pse(n,-1);
        func(a,nge,pge,nse,pse);
        // for(int i=0; i<n; i++) cout<<nge[i]<<" ";
        // cout<<endl;
        // for(int i=0; i<n; i++) cout<<nse[i]<<" ";
        // cout<<endl;
        // for(int i=0; i<n; i++) cout<<pge[i]<<" ";
        // cout<<endl;
        // for(int i=0; i<n; i++) cout<<pse[i]<<" ";
        // cout<<endl;
        for(int i=0; i<n; i++){
            ans=ans+((nge[i]-i)*1ll*(i-pge[i])*1ll*a[i]);
            ans=ans-((nse[i]-i)*1ll*(i-pse[i])*1ll*a[i]);
        }
        return ans;
    }
};