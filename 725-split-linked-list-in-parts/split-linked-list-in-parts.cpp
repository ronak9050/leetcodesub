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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        auto tmp=head;
        while(tmp){
            n++;
            tmp=tmp->next;
        }
        int sz=n/k;
        vector<ListNode*> ans;
        int ct=0;
        ListNode* prev=nullptr;
        auto cur=head;
        while(ct<k){
            int curct=0;
            ans.push_back(cur);
            while(curct<sz+(ct<n%k)){
                prev=cur;
                cur=cur->next;
                curct++;
            }
            if(prev) prev->next=nullptr;
            ct++;
        }
        return ans;
    }
};