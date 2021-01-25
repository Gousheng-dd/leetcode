/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head||!k){
            return NULL;
        }
        ListNode* pAhead=head,*pBehind=head;
        for(int i=0;i<k-1;i++){
            pAhead=pAhead->next;
            if(!pAhead){
                return NULL;
            }
        }
        while(pAhead->next){
            pAhead=pAhead->next;
            pBehind=pBehind->next;
        }
        return pBehind;
    }
};