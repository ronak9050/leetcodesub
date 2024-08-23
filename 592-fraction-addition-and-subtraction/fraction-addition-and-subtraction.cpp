class Solution {
public:
    string fractionAddition(string s) {
        int n=s.size();
        vector<int> num,den;
        int i=0;
        while(i<n){
            string tmp;
            while(i<n && s[i]!='/') tmp.push_back(s[i++]);
            num.push_back(stoi(tmp));
            tmp.clear();
            i++;
            while(i<n && (s[i]!='+' && s[i]!='-')) tmp.push_back(s[i++]);
            den.push_back(stoi(tmp));
        }
        int finden=den[0],sz=num.size(),finum=0;
        for(auto &e:den){
            finden=e*finden/__gcd(e,finden);
        }
        

        for(int i=0 ;i<sz; i++){
            finum+=(num[i]*finden/den[i]);
        }

        
        int com=__gcd(abs(finum),finden);
        finum=finum/com;
        finden=finden/com;
        string ans=to_string(finum)+'/'+to_string(finden);
        return ans;
    }
};