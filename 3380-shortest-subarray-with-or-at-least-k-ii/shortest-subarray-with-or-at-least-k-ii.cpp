class Solution {
public:
    void add(int x,vector<int> &a){
        for(int i=0; i<32; i++){
            if((x>>i)&1) a[i]++;
        }
    }

    bool check(int k, vector<int> &ct){
        int ans=0;
        for(int i=0; i<32; i++){
            if(ct[i]) ans|=(1<<i);
        }
        return ans>=k;
    }

    void remove(int x,vector<int> &a){
        for(int i=0; i<32; i++){
            if((x>>i)&1) a[i]--;
        }
    }

    int minimumSubarrayLength(vector<int>& a, int k) {
        if(*max_element(a.begin(),a.end())>=k) return 1;

        int ans=1e9;
        vector<int> ct(32,0);
        int n=a.size();

        for(int i=0,j=0; i<n; i++){
            add(a[i],ct);
            if(!check(k,ct)) continue;

            while(check(k,ct)){
                remove(a[j],ct);
                j++;
            }
            cout<<i<<" "<<j<<endl;
            ans=min(ans,i-j+2);
        }
        
        return ans==1e9? -1:ans;
    }

};