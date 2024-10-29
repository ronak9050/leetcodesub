int dp[1003][1003];

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
    int n=grid[0].size();

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<m; j++){
            // cout<<j<<" "<<i<<endl;
            if(i==0){
                // cout<<"entering if\n";
                int maxi=0;
                if(j!=0 && grid[j][i]<grid[j-1][i+1]) maxi=max(maxi,dp[j-1][i+1]);
                if(grid[j][i]<grid[j][i+1]) maxi=max(maxi,dp[j][i+1]);
                if(j!=m-1 && grid[j][i]<grid[j+1][i+1]) maxi=max(maxi,dp[j+1][i+1]);
                dp[j][i]=maxi;
                // cout<<"dp="<<dp[j][i]<<endl;
            }
            else if(i==n-1){
                // cout<<"entering else if\n";
                if(j!=0 && grid[j][i]>grid[j-1][i-1])dp[j][i]=1;
                if(grid[j][i]>grid[j][i-1])dp[j][i]=1;
                if(j!=m-1 && grid[j][i]>grid[j+1][i-1])dp[j][i]=1;
                // cout<<"dp="<<dp[j][i]<<endl;
            }
            else{
                // cout<<"entering else\n";
                int maxi=0;

                if(j!=0 && grid[j][i]<grid[j-1][i+1]) maxi=max(maxi,dp[j-1][i+1]);
                if(grid[j][i]<grid[j][i+1]) maxi=max(maxi,dp[j][i+1]);
                if(j!=m-1 && grid[j][i]<grid[j+1][i+1]) maxi=max(maxi,dp[j+1][i+1]);
                dp[j][i]=maxi;

                if((j!=0 && grid[j][i]>grid[j-1][i-1])|| grid[j][i]>grid[j][i-1] || (j!=m-1 && grid[j][i]>grid[j+1][i-1] )) dp[j][i]+=1;
                else dp[j][i]=0;
                // cout<<"dp="<<dp[j][i]<<endl;
            }

        }
    }
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int ans=0;
    for(int i=0; i<m; i++){
        ans=max(ans,dp[i][0]);
    }
        return ans;
    }
};