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
    ListNode* ReverseLL(ListNode* head) {

        ListNode* current = NULL;
        ListNode* ptr = head;
        ListNode* prev = head;
        while (ptr) {
            ListNode* temp = prev->next;
            prev->next = current;
            current = ptr;
            ptr = temp;
            prev = ptr;
        }
        head = current;
        return head;
    }

    ListNode* doubleIt(ListNode* head) {

        ListNode* temp = ReverseLL(head);
        ListNode* duplicate = temp;
        ListNode* prev = head;
        int carry = 0;

        while (temp) {
            int val = ((temp->val) * 2 + carry);
            temp->val = val % 10;
            carry = val / 10;
            temp = temp->next;
        }

        ListNode* ans;

        if (carry) {
            ListNode* node = new ListNode(carry);
            prev->next = node;
            node->next = NULL;
        }

        ans = ReverseLL(duplicate);
        return ans;
    }
};