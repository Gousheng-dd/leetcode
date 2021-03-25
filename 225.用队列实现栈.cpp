/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 *
 * https://leetcode-cn.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (66.81%)
 * Likes:    303
 * Dislikes: 0
 * Total Accepted:    99.7K
 * Total Submissions: 148.9K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通队列的全部四种操作（push、top、pop 和 empty）。
 * 
 * 实现 MyStack 类：
 * 
 * 
 * void push(int x) 将元素 x 压入栈顶。
 * int pop() 移除并返回栈顶元素。
 * int top() 返回栈顶元素。
 * boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty
 * 这些操作。
 * 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["MyStack", "push", "push", "top", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * 输出：
 * [null, null, null, 2, 2, false]
 * 
 * 解释：
 * MyStack myStack = new MyStack();
 * myStack.push(1);
 * myStack.push(2);
 * myStack.top(); // 返回 2
 * myStack.pop(); // 返回 2
 * myStack.empty(); // 返回 False
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 最多调用100 次 push、pop、top 和 empty
 * 每次调用 pop 和 top 都保证栈不为空
 * 
 * 
 * 
 * 
 * 进阶：你能否实现每种操作的均摊时间复杂度为 O(1) 的栈？换句话说，执行 n 个操作的总时间复杂度 O(n)
 * ，尽管其中某个操作可能需要比其他操作更长的时间。你可以使用两个以上的队列。
 * 
 */

// @lc code=start
class MyStack {
public:
    //双队列模拟栈，也可以一个队列模拟；
    //区别在于双队列入栈操作需要一个搬到另一个
    //单队列只需入队后将前n个出队再入队
    /** Initialize your data structure here. */
    MyStack() {
        current=0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(q[current].empty()){
            q[current].push(x);
            return;
        }
        q[1-current].push(x);
        while(!q[current].empty()){
            q[1-current].push(q[current].front());
            q[current].pop();
        }
        current=1-current;
        return ;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q[current].empty()){
            return -1;
        }
        int tem=q[current].front();
        q[current].pop();
        return tem;
    }
    
    /** Get the top element. */
    int top() {
        if(q[current].empty()){
            return -1;
        }
        return q[current].front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q[current].empty();
    }
private:
    queue<int > q[2];
    int current;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

