/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (56.35%)
 * Likes:    834
 * Dislikes: 0
 * Total Accepted:    210K
 * Total Submissions: 372.5K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) —— 将元素 x 推入栈中。
 * pop() —— 删除栈顶的元素。
 * top() —— 获取栈顶元素。
 * getMin() —— 检索栈中的最小元素。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * 
 * 输出：
 * [null,null,null,null,-3,null,0,-2]
 * 
 * 解释：
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * pop、top 和 getMin 操作总是在 非空栈 上调用。
 * 
 * 
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        while(!oristk.empty()){
            oristk.pop();
        }
        while(!minstk.empty()){
            minstk.pop();
        }
    }
    
    void push(int x) {
        int minnum;
        if(minstk.empty()){
            minnum=x;
        }
        else{
            minnum=minstk.top();
        }
        minnum=min(minnum,x);
        oristk.push(x);
        minstk.push(minnum);
        return ;
    }
    
    void pop() {
        if(oristk.empty()){
            return;
        }
        oristk.pop();
        minstk.pop();
        return ;
    }
    
    int top() {
        if(oristk.empty()){
            return INT_MAX;
        }
        return oristk.top();
    }
    
    int getMin() {
        if(minstk.empty()){
            return INT_MAX;
        }
        return minstk.top();
    }
private:
    stack<int> oristk;
    stack<int> minstk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

