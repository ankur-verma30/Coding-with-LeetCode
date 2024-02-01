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
    int getDecimalValue(ListNode* head) {
        int length=0;
        
        if (head==NULL) return NULL;
        ListNode *temp=head;
        while(temp){
            length++;
            temp=temp->next;
        }
        ListNode *test=head;
        
        int ans=0;
        while(test){
            ans+=test->val*(1<<(length-1));
            length--;
            test=test->next;
        }
        return ans;
        
    }
};