class Solution {
public:
    bool check(vector<vector<int>> &a){
        int n=a.size(),m=a[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                if(a[i][j]!=-1) return 0;
            }
            cout<<endl;
        }
        return 1;
    }

    bool func(int num,vector<vector<int>>&a,vector<int> &left,vector<int> &right,vector<int> &top,vector<int> &bot){
        for(int i=top[num]; i<=bot[num]; i++){
            for(int j=left[num]; j<=right[num]; j++){
                if(a[i][j]!=num && a[i][j]!=-1) return 0;
            }
        }
        for(int i=top[num]; i<=bot[num]; i++){
            for(int j=left[num]; j<=right[num]; j++){
                a[i][j]=-1;
            }
        }

        right[num]=-1;
        for(int i=1; i<=60; i++){
            if(right[i]!=-1){
                func(i,a,left,right,top,bot);
            }
        }
        return 1;
    }

    bool isPrintable(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<int> left(61,m+1),right(61,-1),top(61,n+1),bot(61,-1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                left[a[i][j]]=min(left[a[i][j]],j);
                right[a[i][j]]=max(right[a[i][j]],j);
                top[a[i][j]]=min(top[a[i][j]],i);
                bot[a[i][j]]=max(bot[a[i][j]],i);
            }
        }
        
        for(int i=1; i<=60; i++){
            if(right[i]!=-1){
                func(i,a,left,right,top,bot);
            }
        }
        return check(a);
    }
};