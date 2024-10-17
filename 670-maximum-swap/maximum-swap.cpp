class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        if(n==1) return num;
        int ind=n-1;
        vector<int> pos(n,-1);
        for(int i=n-2; i>=0; i--){
            if(s[i]<s[ind]) pos[i]=ind;
            else if(s[i]>s[ind]) ind=i;
        }
        for(int i=0; i<n; i++){
            if(pos[i]!=-1){
                swap(s[i],s[pos[i]]);
                break;
            }
        }
        return stoi(s);
    }
};