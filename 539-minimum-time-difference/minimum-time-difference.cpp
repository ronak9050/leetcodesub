class Solution {
public:
    int func(string &a,string &b){
        int h1=(a[0]-'0')*10+(a[1]-'0');
        int m1=(a[3]-'0')*10+(a[4]-'0');
        int h2=(b[0]-'0')*10+(b[1]-'0');
        int m2=(b[3]-'0')*10+(b[4]-'0');
        return (h2-h1-1)*60+(60-m1)+m2;
    }

    int findMinDifference(vector<string>& s) {
        sort(s.begin(),s.end());
        int n=s.size();
        int ans=min(func(s[0],s[n-1]),1440-func(s[0],s[n-1]));
        for(int i=1; i<n; i++){
            ans=min(ans,min(func(s[i-1],s[i]),1440-func(s[i-1],s[i])));
        }
        return ans;
    }
};