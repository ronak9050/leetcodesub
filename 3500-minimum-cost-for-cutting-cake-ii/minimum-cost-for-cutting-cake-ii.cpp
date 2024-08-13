#define ll long long
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hor, vector<int>& ver) {
        ll h=1,v=1;
        vector<vector<ll>> pr;
        for(int i=0; i<m-1; i++){
            pr.push_back({hor[i],1});
        }
        for(int i=0; i<n-1; i++){
            pr.push_back({ver[i],0});
        }
        sort(pr.begin(),pr.end());
        reverse(pr.begin(),pr.end());

        ll ans=0; // 1-> h++ 0->v++
        for(int i=0; i<pr.size(); i++){
            if(pr[i][1]==1){
                ans+=pr[i][0]*v;
                h++;
            }
            else{
                ans+=pr[i][0]*h;
                v++;
            }
        }
        return ans;
    }
};