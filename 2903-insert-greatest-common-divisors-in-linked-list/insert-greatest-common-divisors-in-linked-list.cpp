/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==nullptr) return head;
        auto prev=head;
        auto cur=head->next;
        while(cur){
            auto tmp = new ListNode(__gcd(prev->val,cur->val));
            prev->next=tmp;
            tmp->next=cur;
            prev=cur;
            cur=cur->next;
        }
        return head;
    }
};