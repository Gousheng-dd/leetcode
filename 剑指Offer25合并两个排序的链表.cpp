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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* resHead,*resTail;
        if(l1->val<l2->val){
            resHead=l1;
            l1=l1->next;
        }
        else{
            resHead=l2;
            l2=l2->next;
        }
        resTail=resHead;
        while(l1&&l2){
            if(l1->val<l2->val){
                resTail->next=l1;
                resTail=l1;
                l1=l1->next;
            }
            else{
                resTail->next=l2;
                resTail=l2;
                l2=l2->next;
            }
        }
        if(l1){
            resTail->next=l1;
        }
        else{
            resTail->next=l2;
        }
        return resHead;
    }
};