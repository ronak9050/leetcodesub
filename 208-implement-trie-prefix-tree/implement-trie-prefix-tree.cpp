struct Node{
    Node* ptr[26];
    int end=0;
};

class Trie {
public:
    Node* root = new Node();
    Trie() {
        
    }
    
    void insert(string s) {
        Node* cur=root;
        for(int i=0; i<s.size(); i++){
            if(cur->ptr[s[i]-'a']!=nullptr) cur=cur->ptr[s[i]-'a'];
            else{
                Node* tmp=new Node();
                cur->ptr[s[i]-'a']=tmp;
                cur=tmp;
            }
        }
        cur->end=1;
    }
    
    bool search(string s) {
        Node* cur=root;
        for(int i=0; i<s.size(); i++){
            if(cur->ptr[s[i]-'a']!=nullptr) cur=cur->ptr[s[i]-'a'];
            else return 0;
        }
        if(cur->end!=1) return 0;
        return 1;
    }
    
    bool startsWith(string s) {
        Node* cur=root;
        for(int i=0; i<s.size(); i++){
            if(cur->ptr[s[i]-'a']!=nullptr) cur=cur->ptr[s[i]-'a'];
            else return 0;
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */