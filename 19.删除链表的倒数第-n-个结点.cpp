/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (41.17%)
 * Likes:    1255
 * Dislikes: 0
 * Total Accepted:    332.8K
 * Total Submissions: 808.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 * 进阶：你能尝试使用一趟扫描实现吗？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1], n = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中结点的数目为 sz
 * 1 
 * 0 
 * 1 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //快慢指针
        if(!head||n<=0){
            return head;
        }
        ListNode *fast=head,*slow=head,*pNode;
        int i;
        for(i=0;i<n;i++){
            fast=fast->next;
            if(fast==NULL){
                break;
            }
        }
        if(fast==NULL){
            if(i==n-1){
                //删除头结点
                pNode=head;
                head=head->next;
                delete pNode;
                return head;
            }
            else{
                return head;
            }
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        pNode=slow->next;
        slow->next=slow->next->next;
        delete pNode;
        return head;
    }
};
// @lc code=end

