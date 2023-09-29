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
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode *slow=head;
       ListNode *fast;
       
       if(slow==NULL)
       return 0;

       while(slow->next){
           if(slow->val==slow->next->val){
               fast=slow->next->next;
               delete(slow->next);
               slow->next=fast;
           }
           else{
               slow=slow->next;
           }         
    }
     return head; 
        
    }
    
};