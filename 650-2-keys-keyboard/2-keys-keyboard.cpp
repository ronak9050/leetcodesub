class Solution {
public:
    int func(int n){
        if(n==1) return 0;
        int ans=0;
        for(int i=2; i<=n; i++){
            if(n%i==0){
                ans=func(n/i)+i;
                break;
            }
        }
        return ans;
    }
    int minSteps(int n) {
        return func(n);
    }
};