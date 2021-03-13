/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (45.62%)
 * Likes:    891
 * Dislikes: 0
 * Total Accepted:    208K
 * Total Submissions: 453K
 * Testcase Example:  '[1,2,2,1]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode* head) {
        if(!head){
            return true;
        }
        ListNode* pre=NULL,*pnode=head,*right=head;
        //链表长度
        int cnt=0;
        while(pnode){
            pnode=pnode->next;
            cnt++;
        }
        for(int i=0;i<(cnt+1)/2;i++){
            right=right->next;
        }
        pnode=head;
        for(int i=0;i<cnt/2;i++){
            ListNode* next=pnode->next;
            pnode->next=pre;
            pre=pnode;
            pnode=next;
        }
        for(int i=0;i<cnt/2;i++){
            if(pre->val!=right->val){
                return false;
            }
            pre=pre->next;
            right=right->next;
        }
        return true;
    }
};
// @lc code=end

