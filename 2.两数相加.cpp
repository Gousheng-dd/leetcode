/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (39.65%)
 * Likes:    5741
 * Dislikes: 0
 * Total Accepted:    732.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 
 * 题目数据保证列表表示的数字不含前导零
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1||!l2){
            return NULL;
        }
        int carry=0,val,num1,num2;
        ListNode* pNode1=l1,*pNode2=l2,*pHead=NULL,*pTail=NULL,*pNode;
        while(pNode1||pNode2){
            if(pNode1){
                num1=pNode1->val;
                pNode1=pNode1->next;
            }
            else{
                num1=0;
            }
            if(pNode2){
                num2=pNode2->val;
                pNode2=pNode2->next;
            }
            else{
                num2=0;
            }
            val=carry+num1+num2;
            carry=val/10;
            val=val%10;
            pNode=new ListNode;
            pNode->next=NULL;
            pNode->val=val;
            if(!pHead){
                pHead=pTail=pNode;
            }
            else{
                pTail->next=pNode;
                pTail=pTail->next;
            }
        }
        if(carry){
            pNode=new ListNode;
            pNode->next=NULL;
            pNode->val=carry;
            pTail->next=pNode;
            pTail=pTail->next;
        }
        return pHead;
    }
};
// @lc code=end

