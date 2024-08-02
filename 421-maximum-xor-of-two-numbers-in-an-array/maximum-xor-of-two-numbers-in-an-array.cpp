struct Node{
    Node* ptr[2];
    int end=0;
};

class Trie{
    Node* root = new Node();
    public:

    void add(int n){
        Node* cur=root;

        for(int i=30; i>=0; i--){
            int num=(n>>i)&1;
            if(cur->ptr[num]==nullptr){
                Node* tmp=new Node();
                cur->ptr[num]=tmp;
            }
            cur=cur->ptr[num];
        }
        cur->end=1;
    }

    int mxxor(int n){
        Node* cur=root,*cur2=root;
        int oth=0;
        for(int i=30; i>=0; i--){
            int num=(n>>i)&1;
            if(cur2->ptr[1-num]!=nullptr){
                if(!num) oth=(1<<i)|oth;
                cur2=cur2->ptr[1-num];
            }
            else{
                if(num) oth=(1<<i)|oth;
                cur2=cur2->ptr[num];
            }
        }
        return n^oth;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& a) {
        int n=a.size();
        Trie tr;
        for(int i=0; i<n; i++){
            tr.add(a[i]);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans,tr.mxxor(a[i]));
        }
        return ans;
    }
};