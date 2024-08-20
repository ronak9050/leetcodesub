class Solution {
public:
    bool ispal(vector<int>&v){
        int n=v.size();
        for(int i=0; i<n/2; i++){
            if(v[i]!=v[n-1-i]) return false;
        }
        return true;
    }

    bool isStrictlyPalindromic(int n) {
        for(int i=2; i<=n-2; i++){
            vector<int>v;
            int temp=n;
            while(temp){
                v.push_back(temp%i);
                temp=temp/i;
            }
            reverse(v.begin(),v.end());
            if(!ispal(v)) return false;
        }
        return true;
    }
};