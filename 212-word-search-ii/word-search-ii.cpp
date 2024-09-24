struct node{
    node* next[26];
    int end=0;
};
vector<vector<int>> moves={{1,0},{-1,0},{0,1},{0,-1}};

class trie{
    node* root=new node();
    public:

    void insert(string &s){
        auto cur = root;
        for(auto e:s){
            if(cur->next[e-'a']==nullptr){
                node* tmp=new node();
                cur->next[e-'a']=tmp;
            }
            cur=cur->next[e-'a'];
        }
        cur->end=1;
    }
    
    set<string> ans;
    void func(int i,int j,vector<vector<char>>&a,node* cur,string &s,vector<vector<int>> &vis){
        if(cur->next[a[i][j]-'a']==nullptr) return;
        int n=a.size(),m=a[0].size();
        s.push_back(a[i][j]);
        vis[i][j]=1;
        if(cur->next[a[i][j]-'a']->end) ans.insert(s);
        for(auto &e:moves){
            int x=i+e[0],y=j+e[1];
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]) func(x,y,a,cur->next[a[i][j]-'a'],s,vis); 
        }
        vis[i][j]=0;
        s.pop_back();
    }
    vector<string> ret(vector<vector<char>>&a){
        vector<string> pos;
        int n=a.size(),m=a[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                string s;
                vector<vector<int>> vis(n,vector<int>(m,0));
                func(i,j,a,root,s,vis);
            }
        }
        for(auto &e:ans) pos.push_back(e);
        return pos;
    }
};  

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& a, vector<string>& words) {
        trie tr;
        for(auto &e:words) tr.insert(e);
        return tr.ret(a);
    }
};