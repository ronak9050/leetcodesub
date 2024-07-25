class Solution {
public:
    void merge(int l,int m,int r,vector<int>&a){
        int i=l,j=m+1;
        vector<int> tmp;
        while(i<=m && j<=r){
            if(a[i]<=a[j]){
                tmp.push_back(a[i]);
                i++;
            }
            else{
                tmp.push_back(a[j]);
                j++;
            }
        }
        while(i<=m){
            tmp.push_back(a[i]);
            i++;
        }
        while(j<=r){
            tmp.push_back(a[j]);
            j++;
        }

        for(int i=l; i<=r; i++){
            a[i]=tmp[i-l];
        }
    }

    void mergesort(int l,int r,vector<int>&a){
        if(l>=r) return;
        int m=(l+r)/2;
        mergesort(l,m,a);
        mergesort(m+1,r,a);
        merge(l,m,r,a);
    }

    vector<int> sortArray(vector<int>& a) {
        int n=a.size();
        mergesort(0,n-1,a);
        return a;
    }
};