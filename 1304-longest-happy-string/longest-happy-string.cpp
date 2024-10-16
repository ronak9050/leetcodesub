class Solution {
public:
    char check(int a,int b,int c){
        if(a>=b && a>=c) return 'a';
        else if(b>=a && b>=c) return 'b';
        return 'c';
    }

    void adder(string &s,char c,int &a){
        s.push_back(c);
        a--;
    }

    void func(string &s,int &a,int &b,int &c){
        char mx=check(a,b,c);
        int n=s.size();
        if(s.size()<2 || s[n-1]!=mx || (s[n-1]==mx && s[n-2]!=mx)){
            s.push_back(mx);
            if(mx=='a') a--;
            else if(mx=='b') b--;
            else c--;
        }
        else{
            if(mx=='a'){
                if(b) adder(s,'b',b);
                else adder(s,'c',c);
            }
            else if(mx=='b'){
                if(a) adder(s,'a',a);
                else adder(s,'c',c);
            }
            else{
                if(a) adder(s,'a',a);
                else adder(s,'b',b);
            }
        }
    }

    string longestDiverseString(int a, int b, int c) {
        string ans;
        a=min(a,(b+c+1)*2);
        b=min(b,(a+c+1)*2);
        c=min(c,(a+b+1)*2);
        while(a||b||c){
            func(ans,a,b,c);
        }
        return ans;
    }
};