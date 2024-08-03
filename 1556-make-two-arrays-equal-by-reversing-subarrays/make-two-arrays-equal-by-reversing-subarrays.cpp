class Solution {
public:
    bool canBeEqual(vector<int>& a, vector<int>& b) {
        vector<int> ct(1001,0);
        int n=a.size();
        for(int i=0; i<n; i++){
            ct[a[i]]++;
            ct[b[i]]--;
        }
        for(int i=0; i<1001; i++) if(ct[i]) return 0;
        return 1;
    }
};