#define ll long long
class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        int i=n-1,j=n-1;
        ll ans=0;
        while(i>=0){
            if(s[i]=='1'){
                ans=ans+(j-i);
                j--;
            }
            i--;
        }
        return ans;
    }
};