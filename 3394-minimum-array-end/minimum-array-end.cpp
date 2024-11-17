#define ll long long
class Solution {
public:
    long long minEnd(int n, int x) {
        ll ans=x,i=0;
        n--;
        while(n){
            if(!((ans>>i)&1)){
                if(n&1) ans|=(1ll<<i);
                n=n>>1;
            }
            i++;
        }
        return ans;
    }
};