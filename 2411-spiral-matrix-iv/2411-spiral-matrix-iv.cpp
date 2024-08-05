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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int startRow = 0, endRow = m - 1;
        int startCol = 0, endCol = n - 1;

        while (head != nullptr) {
            for (int i = startCol; i <= endCol && head != nullptr; i++) {
                mat[startRow][i] = head->val;
                head = head->next;
            }
            startRow++;

            for (int i = startRow; i <= endRow && head != nullptr; i++) {
                mat[i][endCol] = head->val;
                head = head->next;
            }
            endCol--;

            for (int i = endCol; i >= startCol && head != nullptr; i--) {
                mat[endRow][i] = head->val;
                head = head->next;
            }
            endRow--;

            for (int i = endRow; i >= startRow && head != nullptr; i--) {
                mat[i][startCol] = head->val;
                head = head->next;
            }
            startCol++;
        }

        return mat;
    }
};