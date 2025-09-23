class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
         std::stack<int> s;

    // Step 1: Dequeue all elements from the queue and push them onto the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Pop all elements from the stack and enqueue them back into the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    }
};