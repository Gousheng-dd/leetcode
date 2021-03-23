/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (67.49%)
 * Likes:    1058
 * Dislikes: 0
 * Total Accepted:    149.2K
 * Total Submissions: 221.7K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 
 * 进阶：
 * 
 * 
 * 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 
 * 
 * 
 */

// @lc code=start
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
    //自底向上归并排序
    ListNode* sortList(ListNode* head) {
        if(!head){
            return NULL;
        }
        int cnt=0;
        ListNode* pNode=head,*pHead;
        pHead=new ListNode(-1,head);
        while(pNode){
            cnt++;
            pNode=pNode->next;
        }
        int len;
        for(len=2;len<cnt*2;len*=2){
            int sublen=len/2;
            ListNode*headnode=pHead,*node1=headnode->next,*node2=headnode->next;
            while(node1){
                for(int i=0;i<sublen-1&&node2;i++){
                    node2=node2->next;
                }
                if(!node2){
                    mergeList(headnode,node1,node2,sublen);
                    break;
                }
                ListNode* pnext=node2,*ptem;
                node2=node2->next;
                pnext->next=NULL;

                pnext=node2;
                for(int i=0;i<sublen-1&&pnext;i++){
                    pnext=pnext->next;
                }
                if(pnext){
                    ptem=pnext;
                    pnext=pnext->next;
                    ptem->next=NULL;
                }

                headnode=mergeList(headnode,node1,node2,sublen);
                node1=node2=pnext;
            }
        }
        pNode=pHead->next;
        delete pHead;
        return pNode;
    }
private:
    ListNode* mergeList(ListNode* head,ListNode* node1,ListNode* node2,int len){
        int i=0,j=0;
        while(i<len&&j<len&&node1&&node2){
            if(node1->val<node2->val){
                head->next=node1;
                head=head->next;
                node1=node1->next;
                i++;
            }
            else{
                head->next=node2;
                head=head->next;
                node2=node2->next;
                j++;
            }
        }
        if(i<len&&node1){
            head->next=node1;
            while(i<len-1&&node1){
                node1=node1->next;
                i++;
            }
            return node1;
        }
        if(j<len&&node2){
            head->next=node2;
            while(j<len-1&&node2){
                node2=node2->next;
                j++;
            }
            return node2;
        }
        return NULL;
    }
};
// @lc code=end

