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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head==NULL){//空链表直接返回NULL
            return NULL;
        }
        ListNode* pre,*now=head;
        while(now&&now->val!=val){
            pre=now;
            now=now->next;
        }
        if(!now){//val不存在
            return head;
        }
        if(now==head){//删除结点为第一个
            return head->next;
        }
        pre->next=now->next;
        return head;
    }
};