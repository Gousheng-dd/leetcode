/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (42.87%)
 * Likes:    1224
 * Dislikes: 0
 * Total Accepted:    127.9K
 * Total Submissions: 298.2K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */

// @lc code=start
class Solution {
public:
    //单调栈，找某个位置左右小于自己（从小到大）或大于自己（从大到小）的位置
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0){
            return 0;
        }
        int res=0;
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;i++){
            if(s.empty()){
                s.push(i);
                continue;
            }
            int toph=heights[s.top()];
            while(heights[i]<=toph){
                s.pop();
                if(s.empty()){
                    int size=toph*i;
                    res=max(res,size);
                    break;
                }
                int size=toph*(i-s.top()-1);
                res=max(res,size);
                toph=heights[s.top()];
            }
            s.push(i);
        }
        while(s.size()>1){
            int h=heights[s.top()];
            s.pop();
            int size=h*(n-s.top()-1);
            res=max(res,size);
        }
        if(s.size()==1){
            res=max(res,heights[s.top()]*n);
        }
        return res;
    }
};
// @lc code=end

