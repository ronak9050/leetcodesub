class Solution {
public:
    bool primeSubOperation(vector<int>& a) {
        vector<int> pr;
        vector<bool> prime(1001,1);
        for(int i=2; i<1000; i++){
            if(prime[i]){
                pr.push_back(i);
                for(int j=2*i; j<1000; j+=i) prime[j]=0;
            }
        }

        int mn=0;
        for(int i=0; i<a.size(); i++){
            if(mn>=a[i]) return 0;
            auto it=lower_bound(pr.begin(),pr.end(),a[i]-mn);
            if(it!=pr.begin()){
                it--;
                a[i]-=*it;
            }
            mn=a[i];
        }
        return 1;
    }
};