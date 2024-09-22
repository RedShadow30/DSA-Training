/*  Day 44: Problem 225 - Implement Stacks using Queues
    Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack 
    should support all the functions of a normal stack (push, top, pop, and empty).
    Time taken: 14m
*/

class MyStack {
    deque<int> q1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push_back(x); 
    }
    
    int pop() {
        int n = q1.back();
        q1.pop_back();
        return n;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/* Time Complexity: O(N) because we need to traverse through all N numbers in the while loop.
   Space Complexity: O(N) because we store all N numbers in the deque.
   Explanation: I am using a deque to mimic a stack. The method empty is the same. Push uses 
   push_back() to add new elements to the end. Therefore, when pop() is called, I remove from the end. LIFO
   To see the "top" of a stack, I return the last element of the deque using back() which is equivalent to peek().
*/