class Solution {
public:
    bool lemonadeChange(vector<int>& a) {
        int ct5=0,ct10=0;
        int n=a.size();
        for(int i=0; i<n; i++){
            if(a[i]==5) ct5++;
            else if(a[i]==10){
                if(ct5){
                    ct5--;
                    ct10++;
                }
                else return 0;
            }
            else{
                if(ct5){
                    if(ct10){
                        ct10--;
                        ct5--;
                    }
                    else if(ct5>=3){
                        ct5-=3;
                    }
                    else return 0;
                }
                else return 0;
            }
        }
        return 1;
    }
};