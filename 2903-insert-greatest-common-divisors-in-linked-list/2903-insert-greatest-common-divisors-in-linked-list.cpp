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
          ListNode *slow=head;
        ListNode *fast=head->next;
        
        if(head==NULL || head->next==NULL) return head;

        while(fast!=NULL){
            int a=slow->val;
            int b=fast->val;
            int res=__gcd(a,b);
            ListNode *temp=new ListNode(res);
            temp->next=fast;
            slow->next=temp;
            fast=fast->next;
            slow=slow->next->next;
        }
        return head;
    }


};