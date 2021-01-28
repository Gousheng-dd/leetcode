/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 *
 * https://leetcode-cn.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (49.64%)
 * Likes:    334
 * Dislikes: 0
 * Total Accepted:    28K
 * Total Submissions: 56.3K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
 * 
 * 例如，
 * 
 * [2,3,4] 的中位数是 3
 * 
 * [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 * 
 * 设计一个支持以下两种操作的数据结构：
 * 
 * 
 * void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 * double findMedian() - 返回目前所有元素的中位数。
 * 
 * 
 * 示例：
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 进阶:
 * 
 * 
 * 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 
 * 
 */

// @lc code=start
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int> > bigheap;
    priority_queue<int, vector<int>, greater<int> > smallheap;

    MedianFinder() {

    }
    
    void addNum(int num) {
        if((bigheap.size()+smallheap.size())&0x1){//奇数时放入小堆
            if(bigheap.size()&&num<bigheap.top()){
                bigheap.push(num);
                num=bigheap.top();
                bigheap.pop();
            }
            smallheap.push(num);
        }
        else{//偶数时放入大堆
            if(smallheap.size()&&num>smallheap.top()){
                smallheap.push(num);
                num=smallheap.top();
                smallheap.pop();
            }
            bigheap.push(num);
        }
        return;
    }
    
    double findMedian() {
        if(bigheap.size()+smallheap.size()==0){
            return 0.0;
        }
        if((bigheap.size()+smallheap.size())&0x1){
            return bigheap.top();
        }
        else{
            return (smallheap.top()+bigheap.top())/2.0;
        }
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

