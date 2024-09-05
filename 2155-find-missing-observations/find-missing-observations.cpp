class Solution {
public:
    vector<int> missingRolls(vector<int>& a, int mean, int n) {
        int m=a.size();
        int tot=mean*(m+n);
        for(auto &e:a) tot-=e;
        if(tot<n || tot>6*n) return {};
        vector<int> ans(n,tot/n);
        int sum=accumulate(ans.begin(),ans.end(),0);
        int i=0;
        while(i<n && sum<tot){
            if(ans[i]<6) ans[i]++,sum++;
            else i++;
        }
        return ans;
    }
};