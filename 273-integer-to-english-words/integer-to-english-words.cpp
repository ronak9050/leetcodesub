class Solution {
public:
    map<int,string> one={{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"}};
    map<int,string> ten={{2,"Twenty"},{3,"Thirty"},{4,"Forty"},{5,"Fifty"},{6,"Sixty"},{7,"Seventy"},{8,"Eighty"},{9,"Ninety"}};
    map<int,string> eleth={{10,"Ten"},{11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"}};

    string func(int n){
        string ans;
        vector<string> t(4);
        if(n/100){
            t[0]= one[n/100]+" Hundred ";
            n=n%100;
        }

        if(eleth.find(n)!=eleth.end()){
            t[1]=eleth[n];
            return t[0]+t[1];
        }
        else{
            if(n/10){
                t[2]=ten[n/10]+" ";
                n=n%10;
            }
            if(n){
                t[3]=one[n]+" ";
            }
            ans =t[0]+t[2]+t[3];
        }
        ans.pop_back();
        return ans;
    }

    string numberToWords(int n) {
        if(!n) return "Zero";
        string ans;
        vector<string> t(4);
        if(n/1000000000){
            t[0]=func(n/1000000000)+" Billion ";
            n=n%1000000000;
        }
        if(n/1000000){
            t[1]=func(n/1000000)+" Million ";
            n=n%1000000;
        }
        if(n/1000){
            t[2]=func(n/1000)+" Thousand ";
            n=n%1000;
        }
        if(n){
            t[3]=func(n)+" ";
        }
        ans=t[0]+t[1]+t[2]+t[3];
        ans.pop_back();
        return ans;
    }
};