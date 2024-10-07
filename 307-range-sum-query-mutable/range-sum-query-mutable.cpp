class segment{
    vector<int> st;
    public:
    segment(int n){
        st.resize(4*n);
    }
    void build(int ind,int l,int r,vector<int>&a){
        if(l==r){
            st[ind]=a[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*ind+1,l,mid,a);
        build(2*ind+2,mid+1,r,a);
        st[ind]=st[2*ind+1]+st[2*ind+2];
    }

    int query(int ind,int l,int r,int x,int y){
        if(l>y || r<x) return 0;
        if(x<=l && y>=r) return st[ind];
        int mid=(l+r)/2;
        return query(2*ind+1,l,mid,x,y)+query(2*ind+2,mid+1,r,x,y);
    }

    void update(int ind,int l,int r,int req,int val){
        if(l==r){
            st[ind]=val;
            return;
        }
        int mid=(l+r)/2;
        if(req<=mid) update(ind*2+1,l,mid,req,val);
        else update(ind*2+2,mid+1,r,req,val);
        st[ind]=st[2*ind+1]+st[2*ind+2];
    }
};

class NumArray {
    segment* tre;
    int n;
public:
    NumArray(vector<int>& a) {
        n=a.size();
        tre = new segment(n);
        tre->build(0,0,n-1,a);
    }
    
    void update(int index, int val) {
        tre->update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return tre->query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */