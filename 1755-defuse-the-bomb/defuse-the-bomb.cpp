class Solution {
public:
    vector<int> decrypt(vector<int>& a, int k) {
        int n=a.size();
        if(k==0) return vector<int>(n,0);
        int f=0;
        if(k<0){
            reverse(a.begin(),a.end());
            k=-k;
            f=1;
        }
        
        vector<int> ans;
        int sum=0;
        for(int i=0; i<k; i++) sum+=a[i];
        for(int i=0; i<n; i++){
            sum+=(a[(i+k)%n]);
            sum-=a[i];
            ans.push_back(sum);
        }

        if(f) reverse(ans.begin(),ans.end());
        return ans;
    }
};