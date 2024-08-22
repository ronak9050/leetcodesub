class Solution {
public:
    int findComplement(int n) {
        int ans=0;
        int num=log2l(n);
        for(int i=num; i>=0; i--){
            if(((n>>i)&1)==0) ans=ans|(1<<i);
        }
        return ans;
    }
};