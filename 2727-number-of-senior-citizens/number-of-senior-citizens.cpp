class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0,n1,n2,n;
        for(auto e:details){
            n1=(int)(e[11]-'0')*10;
            n2=(int)(e[12]-'0');
            n=n1+n2;
            if(n>60) ans++;
        }
        return ans;
    }
};