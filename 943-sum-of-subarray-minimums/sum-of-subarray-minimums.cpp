#define ll long long
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(),M=1e9+7;
        stack<ll>st;
        vector<ll> fwd(n,1),bkd(n,1);
        for(int i=0; i<n; i++){
            while(st.size() && arr[st.top()]>=arr[i]) st.pop();
            if(st.size()) fwd[i]=i-st.top();
            else fwd[i]=i+1;
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(st.size() && arr[st.top()]>arr[i]) st.pop();
            if(st.size()) bkd[i]=st.top()-i;
            else bkd[i]=n-i;
            st.push(i);
        }
        ll ans=0;
        for(int i=0; i<n; i++) {
            ans=(ans+(fwd[i]*1ll*bkd[i]*1ll*arr[i])%M)%M;
            // cout<<fwd[i]<<" "<<bkd[i]<<endl;
        }
        return ans;
    }
};