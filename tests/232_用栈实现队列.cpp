/*
 * 题目编号: 232
 * 题目名称: 用栈实现队列
 * 难度: 简单
 *
 * 题目描述:
 * 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
 *
 * 实现 MyQueue 类：
 * - void push(int x) 将元素 x 推到队列的末尾
 * - int pop() 从队列的开头移除并返回元素
 * - int peek() 返回队列开头的元素
 * - boolean empty() 如果队列为空，返回 true；否则，返回 false
 *
 * 说明：
 * - 你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size,
 * 和 is empty 操作是合法的。
 * - 你所使用的语言也许不支持栈。你可以使用 list 或者
 * deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 *
 * 示例 1:
 * 输入:
 * ["MyQueue", "push", "push", "peek", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * 输出:
 * [null, null, null, 1, 1, false]
 *
 * 解释:
 * MyQueue myQueue = new MyQueue();
 * myQueue.push(1); // queue is: [1]
 * myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
 * myQueue.peek();  // return 1
 * myQueue.pop();   // return 1, queue is [2]
 * myQueue.empty(); // return false
 *
 * 提示:
 * - 1 <= x <= 9
 * - 最多调用 100 次 push、pop、peek 和 empty
 * - 假设所有操作都是有效的（例如，一个空的队列不会调用 pop 或者 peek 操作）
 *
 * 进阶：你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n
 * 个操作的总时间复杂度为 O(n)，即使其中一个操作可能花费较长时间。
 */

/*
@Solution
class MyQueue {
public:
    MyQueue();
    void push(int x);
    int pop();
    int peek();
    bool empty();
};
@EndSolution
*/

#include "../leetcode_framework.h"
#include "../template.cpp"

// ==================== 测试代码 ====================

int main() {
  // 使用类型别名，使测试代码可以直接使用 MyStack
  using MyStack = Solution::MyStack;
  
  cout << "开始测试 [232. 用栈实现队列]..." << endl;
  cout << string(50, '-') << endl;

  // 测试用例 1
  {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    RUN_TEST(myQueue.peek(), 1, "测试用例 1: peek() 应返回 1");
    RUN_TEST(myQueue.pop(), 1, "测试用例 1: pop() 应返回 1");
    RUN_TEST(myQueue.empty(), false, "测试用例 1: empty() 应返回 false");
  }

  // 测试用例 2
  {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    RUN_TEST(myQueue.pop(), 1, "测试用例 2: pop() 应返回 1");
    RUN_TEST(myQueue.pop(), 2, "测试用例 2: pop() 应返回 2");
    RUN_TEST(myQueue.peek(), 3, "测试用例 2: peek() 应返回 3");
    RUN_TEST(myQueue.pop(), 3, "测试用例 2: pop() 应返回 3");
    RUN_TEST(myQueue.empty(), true, "测试用例 2: empty() 应返回 true");
  }

  // 测试用例 3：空队列
  {
    MyQueue myQueue;
    RUN_TEST(myQueue.empty(), true, "测试用例 3: 空队列 empty() 应返回 true");
  }

  // 测试用例 4：单个元素
  {
    MyQueue myQueue;
    myQueue.push(5);
    RUN_TEST(myQueue.peek(), 5, "测试用例 4: peek() 应返回 5");
    RUN_TEST(myQueue.pop(), 5, "测试用例 4: pop() 应返回 5");
    RUN_TEST(myQueue.empty(), true, "测试用例 4: empty() 应返回 true");
  }

  // 测试用例 5：多次 push 和 pop
  {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.pop();
    myQueue.push(3);
    myQueue.push(4);
    RUN_TEST(myQueue.peek(), 2, "测试用例 5: peek() 应返回 2");
    RUN_TEST(myQueue.pop(), 2, "测试用例 5: pop() 应返回 2");
    RUN_TEST(myQueue.pop(), 3, "测试用例 5: pop() 应返回 3");
    RUN_TEST(myQueue.pop(), 4, "测试用例 5: pop() 应返回 4");
    RUN_TEST(myQueue.empty(), true, "测试用例 5: empty() 应返回 true");
  }

  TEST_SUMMARY();
  return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【思路分析】
 * 使用两个栈来实现队列的 FIFO（先进先出）特性。
 *
 * 核心思路：
 * - 使用两个栈：stackIn（输入栈）和 stackOut（输出栈）
 * - push 操作：直接压入 stackIn
 * - pop/peek 操作：如果 stackOut 为空，将 stackIn 的所有元素依次弹出并压入
 * stackOut 这样 stackOut 的栈顶就是队列的头部
 *
 * 【算法步骤】
 * 1. push(x): 将 x 压入 stackIn
 * 2. pop():
 *    - 如果 stackOut 为空，将 stackIn 的所有元素转移到 stackOut
 *    - 弹出并返回 stackOut 的栈顶
 * 3. peek():
 *    - 如果 stackOut 为空，将 stackIn 的所有元素转移到 stackOut
 *    - 返回 stackOut 的栈顶（不弹出）
 * 4. empty(): 两个栈都为空时返回 true
 *
 * 【参考解法】
 * class MyQueue {
 * private:
 *     stack<int> stackIn;   // 输入栈
 *     stack<int> stackOut;   // 输出栈
 *
 *     // 将输入栈的元素转移到输出栈
 *     void in2out() {
 *         while (!stackIn.empty()) {
 *             stackOut.push(stackIn.top());
 *             stackIn.pop();
 *         }
 *     }
 *
 * public:
 *     MyQueue() {
 *     }
 *
 *     void push(int x) {
 *         stackIn.push(x);
 *     }
 *
 *     int pop() {
 *         if (stackOut.empty()) {
 *             in2out();
 *         }
 *         int result = stackOut.top();
 *         stackOut.pop();
 *         return result;
 *     }
 *
 *     int peek() {
 *         if (stackOut.empty()) {
 *             in2out();
 *         }
 *         return stackOut.top();
 *     }
 *
 *     bool empty() {
 *         return stackIn.empty() && stackOut.empty();
 *     }
 * };
 *
 * 【图解】
 * 操作序列：push(1), push(2), push(3), pop(), push(4)
 *
 * push(1): stackIn=[1], stackOut=[]
 * push(2): stackIn=[1,2], stackOut=[]
 * push(3): stackIn=[1,2,3], stackOut=[]
 * pop():
 *   - stackOut为空，转移：stackIn=[], stackOut=[3,2,1]
 *   - 弹出：stackOut=[3,2], 返回1
 * push(4): stackIn=[4], stackOut=[3,2]
 *
 * 【复杂度分析】
 * 时间复杂度：
 *   - push: O(1)
 *   - pop: 均摊 O(1)（每个元素最多被转移一次）
 *   - peek: 均摊 O(1)
 *   - empty: O(1)
 * 空间复杂度：O(n)，n 为队列中元素个数
 */
