class MyQueue {
public:
    stack<int>stk,stk2;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk.push(x);
    }
    // 把a栈中的元素推到b栈中
    void moveElement (stack <int> &a, stack<int> &b) {
      while (a.size()) {
        b.push(a.top());
        a.pop();
      }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        moveElement(stk, stk2);
        int res = stk2.top();
        stk2.pop();
        moveElement(stk2, stk);
        return res;
    }
    
    /** Get the front element. */
    int peek() {
         moveElement(stk, stk2);
        int res = stk2.top();
        moveElement(stk2, stk);
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */