class Stack {
public:
    queue<int> my_queue;
    // Push element x onto stack.
    void push(int x) {
        my_queue.push(x);
        for(int i=0; i<my_queue.size()-1; ++i) {
            /* 12311 will crash */
        /* while(my_queue.front() != x) { */
            my_queue.push(my_queue.front());
            my_queue.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        my_queue.pop();
    }

    // Get the top element.
    int top() {
        return my_queue.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return my_queue.empty();
    }
};
