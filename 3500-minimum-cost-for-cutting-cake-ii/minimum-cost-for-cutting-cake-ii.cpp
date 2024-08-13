#define ll long long
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hor, vector<int>& ver) {
        ll h=1,v=1;
        sort(hor.begin(),hor.end(),greater<int>());
        sort(ver.begin(),ver.end(),greater<int>());

        ll ans=0; // 1-> h++ 0->v++
        int i=0,j=0;
        while(i<m-1 && j<n-1){
            if(hor[i]>ver[j]){
                ans=ans+hor[i]*v;
                h++;
                i++;
            }
            else{
                ans=ans+ver[j]*h;
                v++;
                j++;
            }
        }
        while(i<m-1){
            ans=ans+hor[i]*v;
            h++;
            i++;
        }
        while(j<n-1){
            ans=ans+ver[j]*h;
            v++;
            j++;
        }
        return ans;
    }
};