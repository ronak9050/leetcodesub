class Solution {
public:
    map<int,string> one={{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"}};
    map<int,string> ten={{2,"Twenty"},{3,"Thirty"},{4,"Forty"},{5,"Fifty"},{6,"Sixty"},{7,"Seventy"},{8,"Eighty"},{9,"Ninety"}};
    map<int,string> eleth={{10,"Ten"},{11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"}};

    string func(int n){
        string ans;
        if(n/100){
            ans=one[n/100]+" Hundred ";
            n=n%100;
        }

        if(eleth.find(n)!=eleth.end()){
            ans=ans+eleth[n]+" ";
        }
        else{
            if(n/10){
                ans=ans+ten[n/10]+" ";
                n=n%10;
            }
            if(n){
                ans=ans+one[n]+" ";
            }
        }
        ans.pop_back();
        return ans;
    }

    string numberToWords(int n) {
        if(!n) return "Zero";
        string ans;
        if(n/1000000000){
            ans=ans+func(n/1000000000)+" Billion ";
            n=n%1000000000;
        }
        if(n/1000000){
            ans=ans+func(n/1000000)+" Million ";
            n=n%1000000;
        }
        if(n/1000){
            ans=ans+func(n/1000)+" Thousand ";
            n=n%1000;
        }
        if(n){
            ans=ans+func(n)+" ";
        }
        ans.pop_back();
        return ans;
    }
};