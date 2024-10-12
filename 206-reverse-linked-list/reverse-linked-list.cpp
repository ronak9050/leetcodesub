class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* next=NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev = curr;
            curr=next;
        }
        return prev;
    }
};