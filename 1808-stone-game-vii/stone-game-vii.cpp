class Solution {
public:
    vector<vector<int>> dp ;
     int f(vector<int> &v, int st, int end,int sum) {
        if (st >= end || sum <= 0) return 0; // If there is only one stone, the score difference is 0.
        if (dp[st][end] != -1) return dp[st][end];  
        int front_score , end_score ;

        front_score = sum - v[st] - f(v , st+1 , end , sum-v[st]) ;
        end_score = sum - v[end] - f(v , st , end-1 , sum-v[end]) ;
        return dp[st][end] = max(front_score , end_score);
    }
    int stoneGameVII(vector<int>& v) {
        int n = v.size() , sum = 0 ;
        for(auto a : v) sum += a ;
        dp.clear() ;
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return  f(v , 0 , n-1,sum)  ;
    }
};