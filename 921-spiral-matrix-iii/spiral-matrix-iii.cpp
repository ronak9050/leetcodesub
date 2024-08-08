class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int r, int c, int rst, int cst) {
        vector<vector<int>> ans(r*c,vector<int>(2));
        int pt=0,top=rst,left=cst-1,bot=rst+1,right=cst+1,i;
        cout<<top<<" "<<bot<<" "<<left<<" "<<right<<endl;

        while(pt<r*c){
            for(i=left+1; i<=right; i++){
                if(i<0) i=0;
                if(i>=c || top<0) break;
                if(pt<r*c) ans[pt++]={top,i};
            }
            top--;
            for(i=top+2; i<=bot; i++){
                if(i<0) i=0;
                if(i>=r || right>=c) break;
                if(pt<r*c) ans[pt++]={i,right};
            }
            right++;
            for(i=right-2; i>=left; i--){
                if(i>=c) i=c-1;
                if(i<0 || bot>=r) break;
                if(pt<r*c) ans[pt++]={bot,i};
            }
            bot++;
            for(i=bot-2; i>top; i--){
                if(i>=r) i=r-1;
                if(i<0 || left<0) break;
                if(pt<r*c) ans[pt++]={i,left};
            }
            left--;
            cout<<top<<" "<<bot<<" "<<left<<" "<<right<<endl;
        }
        return ans;
    }
};