class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size(),ans=0;
        for(int i=0; i<n-2; i++){
            for(int j=0; j<m-2; j++){
                vector<int> ct(10,0),rsum(3,0),csum(3,0);
                for(int p=i; p<i+3; p++){
                    for(int q=j; q<j+3; q++){
                        if(a[p][q]>0 && a[p][q]<10) ct[a[p][q]]++;
                        rsum[p-i]+=a[p][q];
                        csum[q-j]+=a[p][q];
                    }
                }
                int f=1;
                for(int k=1; k<10; k++) if(!ct[k]) f=0;
                for(int k=1; k<3; k++) if(rsum[k]!=rsum[k-1] || csum[k]!=csum[k-1]) f=0;
                int dia1=a[i][j]+a[i+1][j+1]+a[i+2][j+2];
                int dia2=a[i+2][j]+a[i+1][j+1]+a[i][j+2];
                if(rsum[0]!=dia1 || rsum[0]!=dia2) f=0;
                if(f) ans++;
            }
        }
        return ans;
    }

};