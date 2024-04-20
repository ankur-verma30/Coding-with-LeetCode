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
    int pairSum(ListNode* head) {
        if (head == NULL)
            return 0;

        ListNode* temp1 = head;
        int length = 0;

        while (temp1 != NULL) {
            length++;
            temp1 = temp1->next;
        }

        stack<int> st;

        int i = 0;
        ListNode* temp2 = head;
        while (i < length / 2) {
            st.push(temp2->val);
            temp2 = temp2->next;
            i++;
        }

        int maxSum = 0;
        while (i < length && temp2 != NULL) {
            int value1 = st.top();
            st.pop();
            int value2 = temp2->val;
            maxSum = max(maxSum, (value1 + value2));
            temp2 = temp2->next;
            i++;
        }

        return maxSum;
    }
};