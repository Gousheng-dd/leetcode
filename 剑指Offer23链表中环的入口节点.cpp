#include<cstdio>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* MeetingNode(ListNode* pHead)
{
    if(!pHead){
        return NULL;
    }
    ListNode* fastNode=pHead->next,*slowNode=pHead;
    while(fastNode&&slowNode){
        if(fastNode==slowNode){
            return fastNode;
        }
        slowNode=slowNode->next;
        fastNode=fastNode->next;
        if(fastNode){
            fastNode=fastNode->next;
        }
    }
    return NULL;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if(!pHead){
        return NULL;
    }
    ListNode* pNode=MeetingNode(pHead);
    if(!pNode){
        return NULL;
    }
    int nodeCnt=0;
    ListNode* ptem=pNode->next;
    while(ptem!=pNode){
        ptem=ptem->next;
        nodeCnt++;
    }
    nodeCnt++;
    ListNode* pAhead=pHead,*pBehind=pHead;
    for(int i=0;i<nodeCnt;i++){
        pAhead=pAhead->next;
    }
    while(pAhead!=pBehind){
        pAhead=pAhead->next;
        pBehind=pBehind->next;
    }
    return pBehind;
}

/*
       -------
      |       |
    1-2-3-4-5-6
*/
ListNode* createList()
{
    ListNode* pHead=new ListNode(1);
    ListNode* pTail=pHead;
    ListNode* pEntry;
    for(int i=2;i<7;i++){
        ListNode* pNew=new ListNode(i);
        if(i==2){
            pEntry=pNew;
        }
        pTail->next=pNew;
        pTail=pNew;
    }
    pTail->next=pEntry;
    return pHead;
}

int main()
{
    ListNode* pHead=createList();
    ListNode* pTem=pHead;
    // for(int i=0;i<9;i++){
    //     printf("%d\n",pTem->val);
    //     pTem=pTem->next;
    // }
    ListNode* pNode=EntryNodeOfLoop(pHead);
    printf("%d\n",pNode->val);
    return 0;
}