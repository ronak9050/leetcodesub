struct node{
    node* next[26];
    int end=0;
};

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

    bool func(int ind,string &s,node* cur){
        int n=s.size();
        if(ind>=n) return cur->end==1;
        bool ans=0;
        if(s[ind]=='.'){
            for(int i=0; i<26; i++){
                if(cur->next[i]!=nullptr){
                    if(func(ind+1,s,cur->next[i])) return 1;
                } 
            }
        }
        else if(cur->next[s[ind]-'a']) return func(ind+1,s,cur->next[s[ind]-'a']);
        return 0;
    }

    bool search(string &s){
        return func(0,s,root);
    }
};

class WordDictionary {
    trie tr;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        tr.insert(word);
    }
    
    bool search(string word) {
        return tr.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */