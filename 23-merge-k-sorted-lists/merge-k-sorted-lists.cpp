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
    ListNode* mergeKLists(vector<ListNode*>& lt) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        int n=lt.size();
        for(int i=0; i<n; i++){
            if(lt[i]!=nullptr) pq.push({lt[i]->val,lt[i]});
        }
        ListNode* head=nullptr,*mov=nullptr;
        while(pq.size()){
            int num=pq.top().first;
            ListNode* cur=pq.top().second;
            pq.pop();
            ListNode* temp=new ListNode(num);
            if(head==nullptr) {
                head=temp;
                mov=temp;
            }
            else{
                mov->next=temp;
                mov=temp;
            }
            if(cur->next!=nullptr) pq.push({cur->next->val,cur->next});
        }
        return head;
    }
};