/*
 * 题目编号: 225
 * 题目名称: 用队列实现栈
 * 难度: 简单
 *
 * 题目描述:
 * 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop
 * 和 empty）。
 *
 * 实现 MyStack 类：
 * - void push(int x) 将元素 x 压入栈顶。
 * - int pop() 移除并返回栈顶元素。
 * - int top() 返回栈顶元素。
 * - boolean empty() 如果栈是空的，返回 true；否则，返回 false。
 *
 * 注意：
 * - 你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size
 * 和 is empty 这些操作。
 * - 你所使用的语言也许不支持队列。你可以使用 list （列表）或者
 * deque（双端队列）来模拟一个队列，只要是标准的队列操作即可。
 *
 * 示例 1:
 * 输入:
 * ["MyStack", "push", "push", "top", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * 输出:
 * [null, null, null, 2, 2, false]
 *
 * 解释:
 * MyStack myStack = new MyStack();
 * myStack.push(1);
 * myStack.push(2);
 * myStack.top();   // 返回 2
 * myStack.pop();   // 返回 2
 * myStack.empty(); // 返回 False
 *
 * 提示:
 * - 1 <= x <= 9
 * - 最多调用 100 次 push、pop、top 和 empty
 * - 每次调用 pop 和 top 都保证栈不为空
 *
 * 进阶：你能否仅用一个队列实现栈？
 */

/*
@Solution
class MyStack {
public:
    MyStack();
    void push(int x);
    int pop();
    int top();
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
  
  cout << "开始测试 [225. 用队列实现栈]..." << endl;
  cout << string(50, '-') << endl;

  // 测试用例 1
  {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    RUN_TEST(myStack.top(), 2, "测试用例 1: top() 应返回 2");
    RUN_TEST(myStack.pop(), 2, "测试用例 1: pop() 应返回 2");
    RUN_TEST(myStack.empty(), false, "测试用例 1: empty() 应返回 false");
  }

  // 测试用例 2
  {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    RUN_TEST(myStack.pop(), 3, "测试用例 2: pop() 应返回 3");
    RUN_TEST(myStack.pop(), 2, "测试用例 2: pop() 应返回 2");
    RUN_TEST(myStack.top(), 1, "测试用例 2: top() 应返回 1");
    RUN_TEST(myStack.pop(), 1, "测试用例 2: pop() 应返回 1");
    RUN_TEST(myStack.empty(), true, "测试用例 2: empty() 应返回 true");
  }

  // 测试用例 3：空栈
  {
    MyStack myStack;
    RUN_TEST(myStack.empty(), true, "测试用例 3: 空栈 empty() 应返回 true");
  }

  // 测试用例 4：单个元素
  {
    MyStack myStack;
    myStack.push(5);
    RUN_TEST(myStack.top(), 5, "测试用例 4: top() 应返回 5");
    RUN_TEST(myStack.pop(), 5, "测试用例 4: pop() 应返回 5");
    RUN_TEST(myStack.empty(), true, "测试用例 4: empty() 应返回 true");
  }

  // 测试用例 5：多次 push 和 pop
  {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.pop();
    myStack.push(3);
    myStack.push(4);
    RUN_TEST(myStack.top(), 4, "测试用例 5: top() 应返回 4");
    RUN_TEST(myStack.pop(), 4, "测试用例 5: pop() 应返回 4");
    RUN_TEST(myStack.pop(), 3, "测试用例 5: pop() 应返回 3");
    RUN_TEST(myStack.pop(), 1, "测试用例 5: pop() 应返回 1");
    RUN_TEST(myStack.empty(), true, "测试用例 5: empty() 应返回 true");
  }

  TEST_SUMMARY();
  return 0;
}

/*
 * ==================== 解题思路 ====================
 *
 * 【思路分析】
 * 使用队列实现栈的 LIFO（后入先出）特性。
 *
 * 方法一：使用两个队列
 * 核心思路：
 * - 使用两个队列：queue1（主队列）和 queue2（辅助队列）
 * - push 操作：将新元素加入 queue1
 * - pop 操作：将 queue1 中除最后一个元素外的所有元素转移到 queue2，
 *   然后弹出并返回 queue1 的最后一个元素，最后交换 queue1 和 queue2
 *
 * 方法二：使用一个队列（进阶）
 * 核心思路：
 * - 只使用一个队列
 * - push 操作：将新元素加入队列，然后将队列中除新元素外的所有元素依次出队再入队
 *   这样新元素就在队列头部了
 * - pop 操作：直接出队即可
 *
 * 【算法步骤（方法一：两个队列）】
 * 1. push(x): 将 x 加入 queue1
 * 2. pop():
 *    - 将 queue1 中除最后一个元素外的所有元素转移到 queue2
 *    - 弹出并返回 queue1 的最后一个元素
 *    - 交换 queue1 和 queue2
 * 3. top(): 类似 pop，但不删除元素
 * 4. empty(): queue1 为空时返回 true
 *
 * 【算法步骤（方法二：一个队列）】
 * 1. push(x):
 *    - 将 x 加入队列
 *    - 将队列中除 x 外的所有元素依次出队再入队
 * 2. pop(): 直接出队
 * 3. top(): 返回队列头部元素
 * 4. empty(): 队列为空时返回 true
 *
 * 【参考解法1：两个队列】
 * class MyStack {
 * private:
 *     queue<int> queue1;
 *     queue<int> queue2;
 *
 * public:
 *     MyStack() {
 *     }
 *
 *     void push(int x) {
 *         queue1.push(x);
 *     }
 *
 *     int pop() {
 *         // 将 queue1 中除最后一个元素外的所有元素转移到 queue2
 *         while (queue1.size() > 1) {
 *             queue2.push(queue1.front());
 *             queue1.pop();
 *         }
 *         // 获取最后一个元素
 *         int result = queue1.front();
 *         queue1.pop();
 *         // 交换 queue1 和 queue2
 *         swap(queue1, queue2);
 *         return result;
 *     }
 *
 *     int top() {
 *         // 类似 pop，但需要保留最后一个元素
 *         while (queue1.size() > 1) {
 *             queue2.push(queue1.front());
 *             queue1.pop();
 *         }
 *         int result = queue1.front();
 *         queue2.push(queue1.front());
 *         queue1.pop();
 *         swap(queue1, queue2);
 *         return result;
 *     }
 *
 *     bool empty() {
 *         return queue1.empty();
 *     }
 * };
 *
 * 【参考解法2：一个队列（进阶）】
 * class MyStack {
 * private:
 *     queue<int> q;
 *
 * public:
 *     MyStack() {
 *     }
 *
 *     void push(int x) {
 *         int n = q.size();
 *         q.push(x);
 *         // 将前面的 n 个元素依次出队再入队
 *         for (int i = 0; i < n; i++) {
 *             q.push(q.front());
 *             q.pop();
 *         }
 *     }
 *
 *     int pop() {
 *         int result = q.front();
 *         q.pop();
 *         return result;
 *     }
 *
 *     int top() {
 *         return q.front();
 *     }
 *
 *     bool empty() {
 *         return q.empty();
 *     }
 * };
 *
 * 【图解（方法二：一个队列）】
 * 操作序列：push(1), push(2), push(3), pop()
 *
 * push(1): q=[1]
 * push(2):
 *   - 先加入：q=[1,2]
 *   - 将1出队再入队：q=[2,1]
 * push(3):
 *   - 先加入：q=[2,1,3]
 *   - 将2,1出队再入队：q=[3,2,1]
 * pop(): 返回3，q=[2,1]
 *
 * 【复杂度分析】
 * 时间复杂度：
 *   - push: O(n)，n 为栈中元素个数
 *   - pop: O(1)
 *   - top: O(1)
 *   - empty: O(1)
 * 空间复杂度：O(n)，n 为栈中元素个数
 */
