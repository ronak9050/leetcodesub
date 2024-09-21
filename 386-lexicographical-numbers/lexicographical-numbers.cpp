class Solution {
public:
    vector<int> ans;
    void func(int cur,int n){
        if(cur>n) return;
        for(int i=0; i<=9; i++){
            if(cur+i>n || cur+i==cur*10) return;
            ans.push_back(cur+i);
            func((cur+i)*10,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        func(1,n);
        return ans;
    }
};