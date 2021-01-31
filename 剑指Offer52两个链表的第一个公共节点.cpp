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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB){
            return NULL;
        }
        int alen=0,blen=0;
        ListNode* aNode=headA;
        while(aNode){
            alen++;
            aNode=aNode->next;
        }
        ListNode* bNode=headB;
        while(bNode){
            blen++;
            bNode=bNode->next;
        }
        aNode=headA,bNode=headB;
        if(alen>blen){
            for(int i=0;i<alen-blen;i++){
                aNode=aNode->next;
            }
        }
        else{
            for(int i=0;i<blen-alen;i++){
                bNode=bNode->next;
            }
        }
        while(aNode&&bNode){
            if(aNode==bNode){
                return aNode;
            }
            aNode=aNode->next;
            bNode=bNode->next;
        }
        return NULL;
    }
};