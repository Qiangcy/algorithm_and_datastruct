class Queue {
public:
    stack<int> my_stack;
    // Push element x to the back of queue.
    void push(int x) {
        if(my_stack.size() == 0) {
            my_stack.push(x);
            return;
        }
        int data = my_stack.top();
        my_stack.pop();
        push(x);
        my_stack.push(data);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        my_stack.pop();
    }

    // Get the front element.
    int peek(void) {
        return my_stack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return my_stack.empty();
    }
};














class Queue {
public:
    stack<int>  my_queue;
    stack<int>  tmp_queue;
    // Push element x to the back of queue.
    void push(int x) {
        my_queue.push(x);
        /* len++; */
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(!my_queue.empty()){
            tmp_queue.push(my_queue.top());
            my_queue.pop();
        }
        tmp_queue.pop();
        while(!tmp_queue.empty()) {
            my_queue.push(tmp_queue.top());
            tmp_queue.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        int res;
        while(!my_queue.empty()){
            tmp_queue.push(my_queue.top());
            my_queue.pop();
        }
        res = tmp_queue.top();
        while(!tmp_queue.empty()) {
            my_queue.push(tmp_queue.top());
            tmp_queue.pop();
        }
        return res;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return my_queue.empty();
    }
};
