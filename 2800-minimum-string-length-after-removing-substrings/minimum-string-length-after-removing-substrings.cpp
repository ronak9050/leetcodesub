class Solution {
public:
    int minLength(string s) {
        int rm[105]={0};
        int n=s.length();
        
        for(int k=0; k<=n/2; k++){
            for(int i=0; i<n-1; i++){
                while(rm[i]){
                    i++;
                }
                int j=i+1;
                while(rm[j]){
                    j++;
                }
                if(i<n && j<n && s[i]=='A' && s[j]=='B'){
                    rm[i]=1;
                    rm[j]=1;
                    i=j+1;
                }
                else if(i<n && j<n && s[i]=='C' && s[j]=='D'){
                    rm[i]=1;
                    rm[j]=1;
                    i=j+1;
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(rm[i]==0) ans++;
        }
        return ans;
    }
};