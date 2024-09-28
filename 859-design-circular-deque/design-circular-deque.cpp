struct node{
    node* next=nullptr;
    node* prev=nullptr;
    int val;
    node(int num){
        val=num;
    }
};

class MyCircularDeque {
    int k,ct=0;
    node* head=nullptr;
    node* back=nullptr;

public:
    MyCircularDeque(int k) {
        this->k=k;
    }
    
    bool insertFront(int value) {
        if(ct<k){
            if(head){
                node* tmp=new node(value);
                tmp->next=head;
                head->prev=tmp;
                head=tmp;
            }
            else{
                node* tmp=new node(value);
                head=tmp;
                back=tmp;
            }
            ct++;
            return 1;
        }
        return 0;
    }
    
    bool insertLast(int value) {
        if(ct<k){
            if(back){
                node* tmp=new node(value);
                tmp->prev=back;
                back->next=tmp;
                back=tmp;
            }
            else{
                node* tmp=new node(value);
                head=tmp;
                back=tmp;
            }
            ct++;
            return 1;
        }
        return 0;
    }
    
    bool deleteFront() {
        if(!head) return 0;
        if(head==back){
            head=nullptr;
            back=nullptr;
        }
        else{
            auto tmp=head;
            head=head->next;
            delete tmp;
        }
        ct--;
        return 1;
    }
    
    bool deleteLast() {
        if(!head) return 0;
        if(head==back){
            head=nullptr;
            back=nullptr;
        }
        else{
            auto tmp=back;
            back=back->prev;
            delete tmp;
        }
        ct--;
        return 1;
    }
    
    int getFront() {
        if(head) return head->val;
        return -1;
    }
    
    int getRear() {
        if(back) return back->val;
        return -1;
    }
    
    bool isEmpty() {
        if(ct) return 0;
        return 1;
    }
    
    bool isFull() {
        if(ct==k) return 1;
        return 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */