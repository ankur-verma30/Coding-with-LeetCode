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
    ListNode* swapPairs(ListNode* head) {
        int slowVal = 0, fastVal = 0;

        if (head == NULL || head->next == NULL)
            return head;

          ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        while (current->next != NULL && current->next->next != NULL) {
            ListNode* first = current->next;
            ListNode* second = current->next->next;

            // Swapping nodes not the data
            first->next = second->next;
            second->next = first;
            current->next = second;

            // Move to the next pair
            current = current->next->next;
        }

        return dummy->next;
    }
};