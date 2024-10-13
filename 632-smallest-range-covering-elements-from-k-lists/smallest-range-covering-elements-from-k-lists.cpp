class Solution {
public:
    void getans(set<vector<int>> &st,int &l,int &r){
        auto it=st.begin();
        auto itr=st.end();
        itr--;
        int low=it->at(0);
        int high=itr->at(0);
        if((high-low<r-l) || (high-low==r-l && low<l) ){
            l=low;
            r=high;
        }
    }

    vector<int> smallestRange(vector<vector<int>>& a) {
        set<vector<int>> st;
        int k=a.size();
        if(k==1) return {a[0][0],a[0][0]};
        for(int i=0; i<k; i++){
            st.insert({a[i][0],i,1});
        }

        int l=-1e9,r=1e9;
        while(1){
            auto it=*st.begin();
            if(it[2]>=a[it[1]].size()) break;
            getans(st,l,r);
            int i=it[1],j=it[2];
            st.erase(it);
            st.insert({a[i][j],i,j+1});
        }
        getans(st,l,r);
        return {l,r};
    }
};