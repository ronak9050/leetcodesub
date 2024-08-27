class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n=a.size(),ans=0;
        vector<bitset<1000>> hsh(17);
        vector<int> v(n*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<17; j++) if((a[i]>>j)&1) hsh[j][i]=1;
            for(int j=0; j<n; j++) v[i*n+j]=(a[i]&a[j]);
        }

        for(auto &e:v){
            bitset<1000> cur;
            for(int j=0; j<17; j++){
                if((e>>j)&1) cur=(cur|hsh[j]);
            }
            int num=(n-cur.count());
            ans+=num;
        }

        return ans;
    }
};