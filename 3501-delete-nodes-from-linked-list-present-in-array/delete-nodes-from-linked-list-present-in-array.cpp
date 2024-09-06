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
    ListNode* modifiedList(vector<int>& a, ListNode* head) {
        unordered_map<int,int> mp;
        for(auto &e:a) mp[e]++;
        auto cur=head;
        while(cur!=nullptr && mp[cur->val]){
            cur=cur->next;
        }
        auto ret=cur,prev=cur;
        while(cur!=nullptr){
            if(mp[cur->val]){
                prev->next=cur->next;
                cur=cur->next;
            }
            else{
                prev=cur;
                cur=cur->next;
            }
        }
        return ret;
    }
};