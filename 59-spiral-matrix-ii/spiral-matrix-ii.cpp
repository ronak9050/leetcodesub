class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int top=0,bot=n-1,left=0,right=n-1,ct=1;
        while(top<=bot && left<=right){
            for(int i=left; i<=right; i++) ans[top][i]=ct++;
            top++;
            if(top>bot) break;
            for(int i=top; i<=bot; i++) ans[i][right]=ct++;
            right--;
            if(right<left) break;
            for(int i=right; i>=left; i--) ans[bot][i]=ct++;
            bot--;
            for(int i=bot; i>=top; i--) ans[i][left]=ct++;
            left++;
        }
        return ans;
    }
};