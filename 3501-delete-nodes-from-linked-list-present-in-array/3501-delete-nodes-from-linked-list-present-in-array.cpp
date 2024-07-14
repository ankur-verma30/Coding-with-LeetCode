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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;

        for (auto& x : nums)
            st.insert(x);

        ListNode* temp = new ListNode();
        temp->next = head;

        ListNode* curr = temp;

        while (curr->next != NULL) {
            if (st.find(curr->next->val) != st.end()) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else
                curr = curr->next;
        }

        ListNode* start = temp->next;
        delete temp;
        return start;
    }
};