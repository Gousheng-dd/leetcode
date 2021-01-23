/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int m_nValue;
 *     ListNode *m_pNext;
 * };
 */
class Solution {
public:
    void DeleteDuplication(ListNode** pHead) {
        if(!pHead||!(*pHead)){
            return;
        }
        ListNode* pPreNode=NULL,*pNode=*pHead,*pNextNode;
        while(pNode){
            bool needdel=false;
            pNextNode=pNode->m_pNext;
            if(pNextNode && pNode->m_nValue==pNextNode->m_nValue){
                needdel=true;
            }
            if(!needdel){
                pPreNode=pNode;
                pNode=pNode->m_pNext;
            }
            else{
                int value=pNode->m_nValue;
                while(pNode && pNode->m_nValue==value){
                    pNextNode=pNode->m_pNext;
                    delete pNode;
                    pNode=pNextNode;
                }
                if(pPreNode){
                    pPreNode->m_pNext=pNode;
                }
                else{
                    *pHead=pNode;
                }
            }
        }
    }
};