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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int top=0,bot=m-1,left=0,right=n-1,ct=1;
        while(top<=bot && left<=right){
            for(int i=left; i<=right; i++) {
                if(head!=nullptr) {
                    ans[top][i]=head->val;
                    head=head->next;
                }
                else{
                    goto e;
                }
            }
            top++;
            if(top>bot) break;
            for(int i=top; i<=bot; i++) {
                if(head!=nullptr) {
                    ans[i][right]=head->val;
                    head=head->next;
                }
                else{
                    goto e;
                }
            }
            right--;
            if(right<left) break;
            for(int i=right; i>=left; i--) {
                if(head!=nullptr) {
                    ans[bot][i]=head->val;
                    head=head->next;
                }
                else{
                    goto e;
                }
            }
            bot--;
            for(int i=bot; i>=top; i--) {
                if(head!=nullptr) {
                    ans[i][left]=head->val;
                    head=head->next;
                }
                else{
                    goto e;
                }
            }
            left++;
        }
        e:
        return ans;
    }
};