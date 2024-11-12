class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& b, vector<int>& q) {
        sort(b.begin(),b.end());
        vector<pair<int,int>> a;
        for(auto &e:b) a.push_back({e[0],e[1]});
        int n=a.size();
        vector<int> pre(n);
        pre[0]=a[0].second;
        for(int i=1; i<n; i++){
            pre[i]=max(pre[i-1],a[i].second);
        }
        vector<int> ans;
        for(auto e:q){
            auto it=lower_bound(a.begin(),a.end(),pair<int,int>(e+1,0));
            if(it==a.begin()){
                ans.push_back(0);
            }
            else{
                it--;
                ans.push_back(pre[it-a.begin()]);
            }
        }
        return ans;
    }
};