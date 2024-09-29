#define ll long long
class Solution {
public:
    char kthCharacter(long long k, vector<int>& a) {
        vector<ll> series;
        ll num=k;
        series.push_back(num);
        while(num!=1){
            ll near = log2l(num);
            if((1ll<<near)==num){
                while(num!=1){
                    num=num/2;
                    series.push_back(num);
                }
                break;
            }
            series.push_back(num%(1ll<<near));
            num=num%(1ll<<near);
        }
        reverse(series.begin(),series.end());

        char ans='a';
        for(int i=1; i<series.size(); i++){
            int ind= ceil(log2l(series[i]))-1;
            if(a[ind]){
                if(ans=='z') ans='a';
                else ans++;
            }
        }
        return ans;
    }
};