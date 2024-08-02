class Solution {
public:
    void str(string& ans){
        string x;
        int cnt=1;
        char a;
        for(int i=0; i<ans.size()-1; i++){
            a=ans[i];
            if(ans[i]==ans[i+1]){
                cnt++;
                //cout<<cnt<<endl;
            }
            else{
                //cout<<"here"<<endl;
                x+=char(cnt+'0');
                x+=ans[i];
                //cout<<x<<endl;
                cnt=1;
            }
        }
        if(ans[ans.size()-2]!=ans[ans.size()-1]){x+='1'; x+=ans[ans.size()-1];}
        else{
            //cout<<"here"<<endl;
            x+=char(cnt+'0');
            x+=a;
            cout<<x<<endl;
            cnt=1;
        }
        ans.clear();
        //cout<<x<<" "<<"here"<<endl;
        ans=x;
    }
    string countAndSay(int n) {
        if(n==1){return "1";}
        string ans="11";
        n-=2;
        while(n--){
            str(ans);
        }
        return ans;
    }
};