/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (59.92%)
 * Likes:    555
 * Dislikes: 0
 * Total Accepted:    88.6K
 * Total Submissions: 147.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
        //后半部分翻转，逐个插入
        if(!head){
            return ;
        }
        ListNode* fast=head,*slow=head;
        while(fast->next){
            fast=fast->next;
            if(fast&&fast->next){
                fast=fast->next;
            }
            else{
                break;
            }
            slow=slow->next;
        }
        fast=slow->next;
        slow->next=NULL;
        slow=head;
        ListNode* preNode=NULL;
        while(fast){
            ListNode* pNext=fast->next;
            fast->next=preNode;
            preNode=fast;
            fast=pNext;
        }
        fast=preNode;
        while(fast){
            ListNode* pNext=fast->next;
            fast->next=slow->next;
            slow->next=fast;
            slow=fast->next;
            fast=pNext;
        }
        return ;
    }
};
// @lc code=end

