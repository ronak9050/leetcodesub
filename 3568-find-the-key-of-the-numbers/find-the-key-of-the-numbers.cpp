class Solution {
public:
    void func(string &s){
        while(s.size()<4){
            s.insert(s.begin(),'0');
        }
    }
    int generateKey(int a, int b, int c) {
        string s1=to_string(a);
        string s2=to_string(b);
        string s3=to_string(c);
        func(s1);func(s2);func(s3);
        string ans;
        for(int i=0; i<4; i++){
            ans.push_back(min({s1[i],s2[i],s3[i]}));
        }
        return stoi(ans);
    }
};