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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL || k==0) return head;
        
        int length=0,move=0;
        ListNode *temp=head;
        while(temp){
            length++;
            temp=temp->next;
        }
        if(length!=0) k=k%length;
        if (k == 0) return head; // No rotation needed
        
         move=length-k;

        ListNode *slow;
        ListNode *fast=head;

        

        while(move && fast->next!=NULL){
            slow=fast;
            fast=fast->next;
            move--;
        }
        slow->next=NULL;
        ListNode *curr=fast;

        while(fast->next!=NULL){
            fast=fast->next;
        }
        fast->next=head;
        return curr;
    }
};