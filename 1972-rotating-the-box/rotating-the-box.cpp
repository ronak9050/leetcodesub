class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<char>> ans(m,vector<char>(n,'.'));
        for(int i=0; i<n; i++){
            int ct=0;
            for(int j=0; j<m; j++){
                if(a[i][j]=='#') ct++;
                else if(a[i][j]=='*'){
                    int p=j-1;
                    ans[j][n-1-i]='*';
                    while(ct){
                        ans[p][n-1-i]='#';
                        p--;
                        ct--;
                    }
                }
            }
            int p=m-1;
            while(ct){
                ans[p][n-1-i]='#';
                p--;
                ct--;
            }
        }
        return ans;
    }
};