/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int m_nValue;
 *     ListNode *m_pNext;
 * };
 */
class Solution {
public:
    void deleteNode(ListNode** pListHead,ListNode* pToBeDeleted) {
        if(!pListHead||!pToBeDeleted){//链表或待删除结点为空直接返回
            return;
        }
        if(pToBeDeleted==*pListHead){//只有一个结点
            *pListHead=NULL;
            delete pToBeDeleted;
            pToBeDeleted=NULL;
            return;
        }
        if(pToBeDeleted->m_pNext==NULL){//删除结点为尾结点
            ListNode* pNode=*pListHead;
            while(pNode->m_pNext!=pToBeDeleted){
                pNode=pNode->m_pNext;
            }
            pNode->m_pNext=NULL;
            delete pToBeDeleted;
            pToBeDeleted=NULL;
            return;
        }
        //删除普通结点
        ListNode* pNode=pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue=pNode->m_nValue;
        pToBeDeleted->m_pNext=pNode->m_pNext;
        delete pNode;
        pNode=NULL;
        return;
    }
};