class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int ans=0;
        int n=a.size(),m=a[0].size();
        for(int sz=1; sz<=min(n,m); sz++){
            vector<vector<int>> cur=a;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(i) cur[i][j]+=cur[i-1][j];
                    if(j) cur[i][j]+=cur[i][j-1];
                    if(i&&j) cur[i][j]-=cur[i-1][j-1];
                }
            }

            for(int i=sz-1; i<n; i++){
                for(int j=sz-1; j<m; j++){
                    int ct=cur[i][j];
                    if(i>=sz) ct-=cur[i-sz][j];
                    if(j>=sz) ct-=cur[i][j-sz];
                    if(i>=sz && j>=sz) ct+=cur[i-sz][j-sz];
                    if(ct==sz*sz) ans++;
                }
            }

        }
        return ans;
    }
};