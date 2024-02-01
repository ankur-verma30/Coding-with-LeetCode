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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode *slow=head;
        ListNode *fast=head->next;
        ListNode *prev=head;

        while(fast!=NULL){
            if(fast->val!=0){
                sum+=fast->val;
                fast=fast->next;
            }
            else{
                slow->val=sum;
                sum=0;
                prev=slow;
                slow->next=fast;
                slow=fast;
                fast=fast->next;
            }
        }
        prev->next=NULL;
        return head;
    }
};