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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return NULL;
        }
        ListNode* pPre=head,*pNode=head->next,*pNext,*newHead=head;
        head->next=NULL;
        while(pNode){
            pNext=pNode->next;
            pNode->next=pPre;
            if(!pNext){
                newHead=pNode;
            }
            pPre=pNode;
            pNode=pNext;
        }
        return newHead;
    }
};