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
          if(head == NULL) return NULL;
        ListNode *curr = head, *fast = NULL, *prev = head;
        if(curr -> next == NULL ) return head;
        fast = curr -> next;
        while(fast != NULL){
            if(curr->val == fast->val){
                while(fast != NULL && curr->val == fast->val){
                    fast = fast->next;
                }
                if(prev == head && prev->val == curr->val){
                    prev = fast;
                    head = fast;
                } else prev->next = fast;
                curr = fast;
                if(fast != NULL) fast = fast->next;
            } else {
                prev = curr;
                curr = fast;
                fast = fast->next;
            }
        }
        return head;
    }
};