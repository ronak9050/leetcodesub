#define ll long long

class Solution {
public:
    string ans(ll num,string &s){
        int n=s.size();
        ll org=stol(s);
        ll pos1=num-1,pos2=num+1,pos3=num;
        string t1=to_string(pos1),t2=to_string(pos2),t3=to_string(pos3);
        for(int i=n/2-1; i>=0; i--){
            t1.push_back(t1[i]);
            t2.push_back(t2[i]);
            t3.push_back(t3[i]);
        }
        string sp;
        for(int i=0; i<n-1; i++) sp.push_back('9');
        ll ans1=stol(t1),ans2=stol(t2),ans3=stol(t3),ans4=0;
        if(sp.size()) ans4=stol(sp);
        if(org==ans3){
            if(sp.size() && abs(ans4-org)<=abs(org-ans1) && abs(org-ans4)<=abs(org-ans2)) return sp;
            if(abs(org-ans1)<=abs(ans2-org)) return t1;
            return t2;
        }
        else{
            if(sp.size() && abs(ans4-org)<=abs(org-ans1) && abs(org-ans4)<=abs(org-ans2) && abs(org-ans4)<=abs(org-ans3)) return sp;
            if(abs(org-ans1)<=abs(ans2-org) && abs(org-ans1)<=abs(org-ans3)) return t1;
            else if(abs(org-ans3)<=abs(ans2-org)) return t3;
            return t2; 
        }
    }

    string nearestPalindromic(string s) {
        string tmp;
        int n=s.size();
        for(int i=0; i<ceil(n/2.0); i++) tmp.push_back(s[i]);
        ll num=stol(tmp);
        return ans(num,s);
    }
};