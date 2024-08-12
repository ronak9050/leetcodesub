
class SGtree{
    vector<int>seg;
    public:
        SGtree(int n){
            seg.resize(4*n+1,0);
        }
        
        void build(int ind,int low, int high,vector<int>&a){
            if(low==high){
                seg[ind]=(a[low]>a[low-1] && a[low]>a[low+1]);
                return;
            } 
            int mid=(low+high)/2;
            build(2*ind+1,low,mid,a);
            build(2*ind+2,mid+1,high,a);
            seg[ind]=seg[2*ind+1]+seg[ind*2+2];
        }

        int query(int ind,int low,int high,int l,int r){
            if(l>high || r<low) return 0;
            if(l<=low && high<=r) return seg[ind];
            
            int mid=(low+high)/2;
            int left = query(2*ind+1,low,mid,l,r);
            int right = query(2*ind+2,mid+1,high,l,r);
            return left+right;
        }

        void update(int ind,int low,int high,int i,vector<int>&a){
            if(low==high){
                seg[ind]=(a[low]>a[low-1] && a[low]>a[low+1]);
                return;
            }

            int mid=(low+high)/2;
            if(mid>=i) update(2*ind+1,low,mid,i,a);
            else update(2*ind+2,mid+1,high,i,a);

            seg[ind]=seg[2*ind+1]+seg[2*ind+2];
        }

        void give(){
            for(auto &e:seg) cout<<e<<" ";
            cout<<endl;
        }
};


class Solution {
public:
    vector<int> countOfPeaks(vector<int>& a, vector<vector<int>>& q) {
        int n=a.size(),m=q.size();
        a.insert(a.begin(),1e6);
        a.push_back(1e6);
        SGtree sg(n);
        sg.build(0,1,n,a);
        vector<int> ans;
        // sg.give();
        for(auto &e:q){
            if(e[0]==1){
                ans.push_back(sg.query(0,1,n,e[1]+2,e[2]));
            }
            else{
                a[e[1]+1]=e[2];
                sg.update(0,1,n,e[1]+1,a);
                if(e[1]>0)sg.update(0,1,n,e[1],a);
                if(e[1]<n-1) sg.update(0,1,n,e[1]+2,a);
            }
        }
        return ans;
    }
};