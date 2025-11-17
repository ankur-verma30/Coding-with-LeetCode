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
        int startCol=0,startRow=0;
        int endCol=n-1,endRow=m-1;

        int total=m*n,count=0,val=0;
        vector<vector<int>>matrix(m,vector<int>(n,0));
        
        while(count<total){

            for(int i=startCol;i<=endCol && count<total ;i++){
                if(head) {
                    val=head->val;
                    head=head->next;
                }
                else val=-1;
                matrix[startRow][i]=val;
                count++;
            }

            startRow++;

            for(int i=startRow;i<=endRow && count<total ;i++){
                 if(head) {
                    val=head->val;
                    head=head->next;
                }
                else val=-1;
                matrix[i][endCol]=val;
                count++;
        
            }
            endCol--;

            for(int i=endCol;i>=startCol && count<total;i--){
                 if(head) {
                    val=head->val;
                    head=head->next;
                }
                else val=-1;
                matrix[endRow][i]=val;
                count++;
            }
            endRow--;

            for(int i=endRow;i>=startRow && count<total ;i--){
                 if(head) {
                    val=head->val;
                    head=head->next;
                }
                else val=-1;
                matrix[i][startCol]=val;
                count++;
            }
            startCol++;
        }

        return matrix;
    }
};
